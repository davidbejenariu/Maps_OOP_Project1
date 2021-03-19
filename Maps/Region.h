//
// Created by david on 17/03/2021.
//

#ifndef MAPS_REGION_H
#define MAPS_REGION_H

#include "City.h"
#include <queue>
#include <stack>

using namespace std;

class Region
{
public:
    // constructori si destructori
    Region();
    Region(int citiesCount, const City *cities);
    Region(const Region &W);
    ~Region();

    // gettere si settere
    City *getCities();

    // 2 tipuri de functie pentru adaugarea unui oras
    virtual void addCity(City &A);
    virtual void addCity(double x, double y);

    // operatori supraincarcati
    void *operator new[](size_t size);
    void operator delete[](void *p);
    Region &operator=(const Region &W);
    friend ostream &operator<<(ostream &out, const Region &H);

protected:
    int m_citiesCount;
    City *m_cities;

    const int maxCities = 100;
    const double inf = 1 << 30;

private:
    // friend class GeneralGraph;
};

#endif //MAPS_REGION_H