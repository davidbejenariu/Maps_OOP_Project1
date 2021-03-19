//
// Created by david on 17/03/2021.
//

#include "Tree.h"

int Tree::findLCA(int A, int B)
{
    stack <int> path1, path2;
    int node;

    path1.push(A);
    node = A;

    while (node)
    {
        node = m_cities[node].getParent().getIndex();
        path1.push(node);
    }

    path2.push(B);
    node = B;

    while (node)
    {
        node = m_cities[node].getParent().getIndex();
        path2.push(node);
    }

    int top1, top2, LCA;

    while (!path1.empty() && !path2.empty())
    {
        top1 = path1.top();
        top2 = path2.top();

        if (top1 != top2)
            break;
        else
        {
            LCA = top1;

            path1.pop();
            path2.pop();
        }
    }

    return LCA;
}

double Tree::getShortestPath(int A, int B)
{
    double dist = 0;
    int node = A, LCA = this->findLCA(A, B);

    while (node != LCA)
    {
        dist += m_cities[node].getParent().getDistance();
        node = m_cities[node].getParent().getIndex();
    }

    node = B;

    while (node != LCA)
    {
        dist += m_cities[node].getParent().getDistance();
        node = m_cities[node].getParent().getIndex();
    }

    return dist;
}

// A is the parent and B is the child
void Tree::addStreet(int A, int B)
{
    m_cities[A].addNeighbour(m_cities[B]);
    m_cities[B].addNeighbour(m_cities[A]);

    m_cities[B].setParent(m_cities[A]);
}