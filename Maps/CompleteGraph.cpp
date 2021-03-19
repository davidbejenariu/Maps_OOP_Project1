//
// Created by david on 17/03/2021.
//

#include "CompleteGraph.h"

double CompleteGraph::getShortestPath(int A, int B)
{
    return m_cities[A].euclidianDistance(m_cities[B]);
}

// as this is a complete graph, when adding a city, we'll also need to add connections to all other cities
void CompleteGraph::addCity(City &A)
{
    Region::addCity(A);

    for (int i = 0; i < m_citiesCount - 1; ++i)
    {
        m_cities[m_citiesCount - 1].addNeighbour(m_cities[i]);
        m_cities[i].addNeighbour(m_cities[m_citiesCount - 1]);
    }
}

void CompleteGraph::addCity(double x, double y)
{
    Region::addCity(x, y);

    for (int i = 0; i < m_citiesCount - 1; ++i)
    {
        m_cities[m_citiesCount - 1].addNeighbour(m_cities[i]);
        m_cities[i].addNeighbour(m_cities[m_citiesCount - 1]);
    }
}
