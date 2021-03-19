//
// Created by david on 17/03/2021.
//

#include "GeneralGraph.h"

typedef pair <double, int> pdi;

double GeneralGraph::getShortestPath(int A, int B)
{
    priority_queue <pdi, vector <pdi>, greater <pdi>> Heap;
    double *dist = new double[m_citiesCount];
    bool *visited = new bool[m_citiesCount];

    for (int i = 0; i < m_citiesCount; ++i)
    {
        dist[i] = inf;
        visited[i] = false;
    }

    dist[A] = 0;
    Heap.push(make_pair(0, A));

    while (!Heap.empty())
    {
        int city = Heap.top().second; Heap.pop();
        int N = m_cities[city].getNeighboursCount();
        Neighbour *neighbours = m_cities[city].getNeighbours();

        if (visited[city])
            continue;
        else
            visited[city] = true;

        for (int i = 0; i < N; ++i)
        {
            int w = neighbours[i].getIndex();
            double d = neighbours[i].getDistance();

            if (dist[city] + d < dist[w])
            {
                dist[w] = dist[city] + d;
                Heap.push(make_pair(dist[w], w));
            }
        }
    }

    if (dist[B] != inf)
        return dist[B];
    else
        return -1;
}

void GeneralGraph::addStreet(int A, int B)
{
    m_cities[A].addNeighbour(m_cities[B]);
    m_cities[B].addNeighbour(m_cities[A]);
}
