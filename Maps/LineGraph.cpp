//
// Created by david on 18/03/2021.
//

#include "LineGraph.h"

double LineGraph::getShortestPath(int A, int B)
{
    if (A > B)
        swap(A, B);

    double dist = 0;

    for (int city = A; city < B; ++city)
        dist += m_cities[city].euclidianDistance(m_cities[city + 1]);

    return dist;
}

void LineGraph::addCity(City &A)
{
    Region::addCity(A);

    if (m_citiesCount > 1)
        m_cities[m_citiesCount - 2].addNeighbour(m_cities[m_citiesCount - 1]);
}

void LineGraph::addCity(double x, double y)
{
    Region::addCity(x, y);

    if (m_citiesCount > 1)
        m_cities[m_citiesCount - 2].addNeighbour(m_cities[m_citiesCount - 1]);
}
