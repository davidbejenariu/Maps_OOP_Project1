//
// Created by david on 15/03/2021.
//

#include "City.h"

City::City() :
        m_x(0), m_y(0), m_cIndex(-1), m_neighboursCount(0), m_neighbours(nullptr), m_parent(Neighbour(0, 0)) {}

//City::City(double x, double y, int cIndex, int neighboursCount, Neighbour *neighbours) :
//        m_x(x), m_y(y), m_cIndex(cIndex), m_neighboursCount(neighboursCount)
//{
//    if (neighboursCount > 0)
//    {
//        m_neighbours = new Neighbour[neighboursCount]; // need default constructor
//
//        for (int i = 0; i < neighboursCount; ++i)
//            m_neighbours[i] = neighbours[i];
//    }
//}

City::City(double x, double y, int cIndex) :
        m_x(x), m_y(y), m_cIndex(cIndex), m_neighboursCount(0), m_parent(Neighbour(0, 0))
{
    m_neighbours = new Neighbour[maxNeighbours];
}

City::City(const City &B)
{
    m_x = B.m_x;
    m_y = B.m_y;
    m_cIndex = B.m_cIndex;
    m_neighboursCount = B.m_neighboursCount;
    m_neighbours = B.m_neighbours;
}

City::~City()
{
    if (m_neighboursCount) delete[] m_neighbours;
}

void *City::operator new[](size_t size)
{
    void *p;

    p = malloc(size);

    if (!p)
    {
        bad_alloc ba;

        throw ba;
    }

    return p;
}

void City::operator delete[](void *p)
{
    free(p);
}

ostream &operator<<(ostream &out, const City &A)
{
    out << "\tm_cIndex: " << A.m_cIndex << '\n';
    out << "\tm_x: " << A.m_x << ", m_y: " << A.m_y << '\n';
    out << "\tm_neighboursCount: " << A.m_neighboursCount;

    if (A.m_neighboursCount > 0)
    {
        out << "\n\t\t";

        for (int i = 0; i < A.m_neighboursCount; ++i)
            out << "{" << A.m_neighbours[i] << "} ";
    }

    return out;
}

City &City::operator=(const City &B)
{
    m_x = B.m_x;
    m_y = B.m_y;
    m_cIndex = B.m_cIndex;
    m_neighboursCount = B.m_neighboursCount;
    m_neighbours = B.m_neighbours;

    return *this;
}

double City::getX()
{
    return m_x;
}

void City::setX(double x)
{
    m_x = x;
}

double City::getY()
{
    return m_y;
}

void City::setY(double y)
{
    m_y = y;
}

int City::getIndex()
{
    return m_cIndex;
}

void City::setIndex(int newIndex)
{
    m_cIndex = newIndex;
}

inline double City::euclidianDistance(City &B)
{
    double x1 = m_x;
    double x2 = B.getX();
    double y1 = m_y;
    double y2 = B.getY();

    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void City::addNeighbour(City &B)
{
    Neighbour N(B.m_cIndex, euclidianDistance(B));

    if (!m_neighboursCount)
    {
        m_neighbours = new Neighbour[maxNeighbours];
    }

    m_neighbours[m_neighboursCount++] = N;
}

int City::getNeighboursCount()
{
    return m_neighboursCount;
}

Neighbour *City::getNeighbours()
{
    return m_neighbours;
}

Neighbour City::getParent()
{
    return m_parent;
}

void City::setParent(City &parent)
{
    Neighbour p(parent.getIndex(), this->euclidianDistance(parent));

    m_parent = p;
}