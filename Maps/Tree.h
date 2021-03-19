//
// Created by david on 17/03/2021.
//

#ifndef MAPS_TREE_H
#define MAPS_TREE_H

#include "Region.h"

/// root will always be the city of index 0

class Tree: public Region
{
public:
    int findLCA(int A, int B);
    double getShortestPath(int A, int B);
    void addStreet(int A, int B);

protected:

private:

};

#endif //MAPS_TREE_H