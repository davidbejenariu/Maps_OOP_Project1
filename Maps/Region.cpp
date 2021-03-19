//
// Created by david on 17/03/2021.
//

#include "Region.h"

Region::Region() :
        m_citiesCount(0), m_cities(nullptr) {}

Region::Region(int citiesCount, const City *cities) :
        m_citiesCount(citiesCount)
{
    if (citiesCount > 0)
    {
        m_cities = new City[maxCities];

        for (int i = 0; i < citiesCount; ++i)
            m_cities[i] = cities[i];
    }
}

Region::Region(const Region &W)
{
    m_citiesCount = W.m_citiesCount;
    m_cities = W.m_cities;
}

Region::~Region()
{
    if (m_citiesCount) delete[] m_cities;
}

void *Region::operator new[](size_t size)
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

void Region::operator delete[](void *p)
{
    free(p);
}

ostream &operator<<(ostream &out, const Region &H)
{
    out << "m_citiesCount: " << H.m_citiesCount << '\n';

    for (int i = 0; i < H.m_citiesCount - 1; ++i)
        out << H.m_cities[i] << "\n";

    out << H.m_cities[H.m_citiesCount - 1];

    return out;
}

Region &Region::operator=(const Region &W)
{
    m_citiesCount = W.m_citiesCount;
    m_cities = W.m_cities;

    return *this;
}

City *Region::getCities()
{
    return m_cities;
}

void Region::addCity(City &A)
{
    if (!m_citiesCount)
    {
        m_cities = new City[maxCities];
    }

    m_cities[m_citiesCount++] = A;
}

void Region::addCity(double x, double y)
{
    City X(x, y, m_citiesCount);

    if (!m_citiesCount)
    {
        m_cities = new City[maxCities];
    }

    m_cities[m_citiesCount++] = X;
}