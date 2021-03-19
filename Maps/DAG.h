//
// Created by david on 18/03/2021.
//

#ifndef MAPS_DAG_H
#define MAPS_DAG_H

#include "Region.h"

class DAG: public Region
{
public:
    void topologicalSort(int city, bool *visited, stack <int> &S);
    double getShortestPath(int A, int B);
    void addStreet(int A, int B);

protected:

private:

};

#endif //MAPS_DAG_H