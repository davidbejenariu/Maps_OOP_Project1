//
// Created by david on 18/03/2021.
//

#include "DAG.h"

void DAG::topologicalSort(int city, bool *visited, stack<int> &S)
{
    int N = m_cities[city].getNeighboursCount();
    Neighbour *neighbours = m_cities[city].getNeighbours();

    visited[city] = true;

    for (int i = 0; i < N; ++i)
    {
        int w = neighbours[i].getIndex();

        if (!visited[w])
            topologicalSort(w, visited, S);
    }

    S.push(city);
}

double DAG::getShortestPath(int A, int B)
{
    stack <int> S;
    double *dist = new double[m_citiesCount];
    bool *visited = new bool[m_citiesCount];

    for (int i = 0; i < m_citiesCount; ++i)
    {
        dist[i] = inf;
        visited[i] = false;
    }

    for (int i = 0; i < m_citiesCount; ++i)
        if (!visited[i])
            topologicalSort(i, visited, S);

    dist[A] = 0;

    while (!S.empty())
    {
        int city = S.top(); S.pop();
        int N = m_cities[city].getNeighboursCount();
        Neighbour *neighbours = m_cities[city].getNeighbours();

        if (dist[city] != inf)
        {
            for (int i = 0; i < N; ++i)
            {
                int w = neighbours[i].getIndex();
                double d = neighbours[i].getDistance();

                if (dist[city] + d < dist[w])
                    dist[w] = dist[city] + d;
            }
        }
    }

    if (dist[B] != inf)
        return dist[B];
    else
        return -1;
}

void DAG::addStreet(int A, int B)
{
    m_cities[A].addNeighbour(m_cities[B]);
}