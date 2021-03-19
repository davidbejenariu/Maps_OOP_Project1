//
// Created by david on 17/03/2021.
//

#ifndef MAPS_GENERALGRAPH_H
#define MAPS_GENERALGRAPH_H

#include "Region.h"

class GeneralGraph: public Region
{
public:
    double getShortestPath(int A, int B);
    void addStreet(int A, int B);

protected:

private:

};

#endif //MAPS_GENERALGRAPH_H