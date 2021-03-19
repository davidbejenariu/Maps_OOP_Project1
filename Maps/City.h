//
// Created by david on 15/03/2021.
//

#ifndef MAPS_CITY_H
#define MAPS_CITY_H

#include <iostream>
#include "Neighbour.h"

using namespace std;

class City
{
public:
    // constructori si destructori
    City();
    City(double x, double y, int cIndex);
    //City(double x, double y, int cIndex, int neighboursCount, Neighbour *neighbours);
    City(const City &B);
    ~City();

    // gettere si settere
    double getX();
    void setX(double x);

    double getY();
    void setY(double y);

    int getIndex();
    void setIndex(int newIndex);

    int getNeighboursCount();

    Neighbour *getNeighbours();

    Neighbour getParent();

    void setParent(City &parent);

    // functie pentru distanta euclidiana dintre orasul this si orasul dat ca parametru
    double euclidianDistance(City &B);

    // functie pentru adaugarea unui vecin
    void addNeighbour(City &B);

    // operatori supraincarcati
    void *operator new[](size_t size);
    void operator delete[](void *p);
    City &operator=(const City &B);
    friend ostream &operator<<(ostream &out, const City &A);

protected:

private:
    double m_x, m_y;
    int m_cIndex;
    int m_neighboursCount;
    Neighbour *m_neighbours;
    Neighbour m_parent; // we'll use it for trees

    const int maxNeighbours = 100;
};

#endif //MAPS_CITY_H