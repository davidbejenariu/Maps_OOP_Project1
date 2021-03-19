//
// Created by david on 17/03/2021.
//

#include "Neighbour.h"

Neighbour::Neighbour() :
        m_nIndex(-1), m_distance(0) {}

Neighbour::Neighbour(int nIndex, double distance) :
        m_nIndex(nIndex), m_distance(distance) {}

ostream &operator<<(ostream &os, const Neighbour &A)
{
    os << "m_nIndex: " << A.m_nIndex << ", m_distance: " << A.m_distance;

    return os;
}

Neighbour &Neighbour::operator=(const Neighbour &B)
{
    m_nIndex = B.m_nIndex;
    m_distance = B.m_distance;

    return *this;
}

int Neighbour::getIndex()
{
    return m_nIndex;
}

double Neighbour::getDistance()
{
    return m_distance;
}
