//
// Created by david on 17/03/2021.
//

#ifndef MAPS_NEIGHBOUR_H
#define MAPS_NEIGHBOUR_H

#include <iostream>

using namespace std;

class Neighbour
{
public:
    // constructori
    Neighbour();
    Neighbour(int nIndex, double distance);

    // gettere si settere
    int getIndex();
    double getDistance();

    // operatori supraincarcati
    Neighbour &operator=(const Neighbour &B);
    friend ostream &operator<<(ostream &os, const Neighbour &A);

protected:

private:
    int m_nIndex;
    double m_distance;
};

#endif //MAPS_NEIGHBOUR_H