//
// Created by david on 18/03/2021.
//

#ifndef MAPS_LINEGRAPH_H
#define MAPS_LINEGRAPH_H

#include "Region.h"

// city0 --- city1 --- city2 --- city3 --- ... --- city n
// adding a new city will also add a link to the last city

class LineGraph: public Region
{
public:
    double getShortestPath(int A, int B);

    // supraincarcarea metodelor din clasa base
    void addCity(City &A);
    void addCity(double x, double y);

protected:

private:

};

#endif //MAPS_LINEGRAPH_H