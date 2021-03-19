//
// Created by david on 19/03/2021.
//

#include "Map.h"

int Map::maxRegions(100);

Map::Map() :
        m_lGraphsCount(0), m_lGraphs(nullptr), m_gGraphsCount(0), m_gGraphs(nullptr),
        m_cGraphsCount(0), m_cGraphs(nullptr), m_treesCount(0), m_trees(nullptr),
        m_DAGsCount(0), m_DAGs(nullptr) {}

Map::~Map()
{
    if (m_lGraphsCount > 0) delete[] m_lGraphs;
    if (m_gGraphsCount > 0) delete[] m_gGraphs;
    if (m_cGraphsCount > 0) delete[] m_cGraphs;
    if (m_treesCount > 0) delete[] m_trees;
    if (m_DAGsCount > 0) delete[] m_DAGs;
}

void *Map::operator new[](size_t size)
{
    void *p;

    p = malloc(size);

    if (!p)
    {
        bad_alloc ba;

        throw ba;
    }

    return p;
}

void Map::operator delete[](void *p)
{
    free(p);
}

ostream &operator<<(ostream &out, const Map &map)
{
    out << "m_lGraphsCount: " << map.m_lGraphsCount << '\n';

    for (int i = 0; i < map.m_lGraphsCount; ++i)
        out << map.m_lGraphs[i] << '\n';

    out << "m_gGraphsCount: " << map.m_gGraphsCount << '\n';

    for (int i = 0; i < map.m_gGraphsCount; ++i)
        out << map.m_gGraphs[i] << '\n';

    out << "m_lGraphsCount: " << map.m_cGraphsCount << '\n';

    for (int i = 0; i < map.m_cGraphsCount; ++i)
        out << map.m_cGraphs[i] << '\n';

    out << "m_lGraphsCount: " << map.m_treesCount << '\n';

    for (int i = 0; i < map.m_treesCount; ++i)
        out << map.m_trees[i] << '\n';

    out << "m_lGraphsCount: " << map.m_DAGsCount << '\n';

    for (int i = 0; i < map.m_DAGsCount; ++i)
        out << map.m_DAGs[i] << '\n';

    return out;
}

void Map::addLineGraph()
{
    if (!m_lGraphsCount)
    {
        m_lGraphs = new LineGraph[maxRegions];
    }

    ++m_lGraphsCount;
}

void Map::addGeneralGraph()
{
    if (!m_gGraphsCount)
    {
        m_gGraphs = new GeneralGraph[maxRegions];
    }

    ++m_gGraphsCount;
}

void Map::addCompleteGraph()
{
    if (!m_cGraphsCount)
    {
        m_cGraphs = new CompleteGraph[maxRegions];
    }

    ++m_cGraphsCount;
}

void Map::addTree()
{
    if (!m_treesCount)
    {
        m_trees = new Tree[maxRegions];
    }

    ++m_treesCount;
}

void Map::addDAG()
{
    if (!m_DAGsCount)
    {
        m_DAGs = new DAG[maxRegions];
    }

    ++m_DAGsCount;
}

int Map::getLineGraphsCount() const
{
    return m_lGraphsCount;
}

LineGraph *Map::getLineGraphs()
{
    return m_lGraphs;
}

int Map::getGeneralGraphsCount() const
{
    return m_gGraphsCount;
}

GeneralGraph *Map::getGeneralGraphs()
{
    return m_gGraphs;
}

int Map::getCompleteGraphsCount() const
{
    return m_cGraphsCount;
}

CompleteGraph *Map::getCompleteGraphs()
{
    return m_cGraphs;
}

int Map::getTreesCount() const
{
    return m_treesCount;
}

Tree *Map::getTrees()
{
    return m_trees;
}

int Map::getDAGsCount() const
{
    return m_DAGsCount;
}

DAG *Map::getDAGs()
{
    return m_DAGs;
}
