//
// Created by david on 19/03/2021.
//

#ifndef MAPS_MAP_H
#define MAPS_MAP_H

#include <iostream>
#include "City.h"
#include "Region.h"
#include "LineGraph.h"
#include "GeneralGraph.h"
#include "CompleteGraph.h"
#include "Tree.h"
#include "DAG.h"

/// nu o sa implementez un constructor cu toti paramentrii intrucat as vrea ca harta sa plece de la zero
/// avand in vedere si unicitatea hartii, nu voi defini constructor de copiere si nici operator de atribuire

class Map
{
public:
    // constructori si destructori
    Map();
    ~Map();

    // gettere
    int getLineGraphsCount() const;
    LineGraph *getLineGraphs();
    int getGeneralGraphsCount() const;
    GeneralGraph *getGeneralGraphs();
    int getCompleteGraphsCount() const;
    CompleteGraph *getCompleteGraphs();
    int getTreesCount() const;
    Tree *getTrees();
    int getDAGsCount() const;
    DAG *getDAGs();

    // operatori supraincarcati
    void *operator new[](size_t size);
    void operator delete[](void *p);
    friend ostream &operator<<(ostream &out, const Map &map);

    // functii de completare
    void addLineGraph();
    void addGeneralGraph();
    void addCompleteGraph();
    void addTree();
    void addDAG();

protected:

private:
    int m_lGraphsCount;
    LineGraph *m_lGraphs;

    int m_gGraphsCount;
    GeneralGraph *m_gGraphs;

    int m_cGraphsCount;
    CompleteGraph *m_cGraphs;

    int m_treesCount;
    Tree *m_trees;

    int m_DAGsCount;
    DAG *m_DAGs;

    static int maxRegions;
};

#endif //MAPS_MAP_H