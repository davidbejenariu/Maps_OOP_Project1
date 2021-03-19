//
// Created by david on 17/03/2021.
//

#ifndef MAPS_COMPLETEGRAPH_H
#define MAPS_COMPLETEGRAPH_H

#include "Region.h"

class CompleteGraph: public Region
{
public:
    double getShortestPath(int A, int B);

    // supraincarcarea metodelor din clasa base
    void addCity(City &A);
    void addCity(double x, double y);

protected:

private:

};


#endif //MAPS_COMPLETEGRAPH_H
