#include "Map.h"
#include <cstring>
#define maxStr 100

using namespace std;

/**
 * m-am gandit ca in locul functiilor addCity/addNeighbour/addStreet sa supraincarc operatorul +=
 * cu toate acestea, mi se pare mai natural sa ramana functii, deci le-am lasat asa :)
 * @return
 *
 * legat de Map, am vrut sa am totul adunat intr-o singura clasa, chiar daca nu o sa definesc
 * mai mult de un obiect de acest tip
 */

void toLower(char command[])
{
    for (int i = 0; command[i]; ++i)
        command[i] = tolower(command[i]);
}

int strToNum(char *p)
{
    int num = 0;

    for (int i = 0; p[i]; ++i)
        num = num * 10 + p[i] - '0';

    return num;
}

int main()
{
//    City A(0, 0, 0), B(1.5, 2.76, 1), C(3, 7.02, 2);
//    City cities[] = {A, B, C};
//    A.addNeighbour(B);
//    A.addNeighbour(C);
//
//    Region H(3, cities);

//    GeneralGraph H;
//
//    H.addCity(A);
//    H.addCity(B);
//    H.addCity(C);
//    H.addCity(5.45, 3.28);
//
//    H.addStreet(0, 1);
//    H.addStreet(1, 2);
//    H.addStreet(3, 2);
//    H.addStreet(3, 0);
//    H.addStreet(2, 0);
//
//    cout << H;
//    cout << '\n' << H.getShortestPath(0, 2);

//    CompleteGraph H;
//
//    H.addCity(A);
//    H.addCity(B);
//    H.addCity(C);
//    H.addCity(5.45, 3.28);
//
//    cout << H;
//    cout << '\n' << H.getShortestPath(0, 1);

//    Tree H;
//
//    H.addCity(A);
//    H.addCity(B);
//    H.addCity(C);
//    H.addCity(5.45, 3.28);
//
//    H.addStreet(0, 1);
//    H.addStreet(0, 2);
//    H.addStreet(1, 3);
//
//    cout << H << '\n' << H.getShortestPath(2, 2);

//    DAG H;
//
//    H.addCity(A);
//    H.addCity(B);
//    H.addCity(C);
//    H.addCity(5.45, 3.28);
//
//    H.addStreet(0, 1);
//    H.addStreet(0, 2);
//    H.addStreet(1, 3);
//
//    cout << H << '\n' << H.getShortestPath(0, 3);

//    LineGraph H;
//
//    H.addCity(A);
//    H.addCity(B);
//    H.addCity(C);
//    H.addCity(5.45, 3.28);
//
//    cout << H << '\n' << H.getShortestPath(0, 3);

    Map M;
    char command[maxStr];
    char regionType[maxStr];
    int index, A, B;
    double x, y;

    cin.getline(command, maxStr);
    toLower(command);

    while (strcmp(command, "quit"))
    {
        toLower(command);

        if (!strcmp(command, "add region"))
        {
            cout << "Insert Region Type (Line/ General/ Complete Graph, Tree or DAG):";
            cin.getline(regionType, maxStr);

            toLower(regionType);

            if (!strcmp(regionType, "line graph")) M.addLineGraph();
            else if (!strcmp(regionType, "general graph")) M.addGeneralGraph();
            else if (!strcmp(regionType, "complete graph")) M.addCompleteGraph();
            else if (!strcmp(regionType, "tree")) M.addTree();
            else if (!strcmp(regionType, "dag")) M.addDAG();
            else cout << "Typo! Try again.\n";
        }

        if (!strcmp(command, "add city"))
        {
            cout << "Insert Region Type (Line/ General/ Complete Graph, Tree or DAG):";
            cin.getline(regionType, maxStr);
            cout << "Insert Index of Region:";
            cin >> index;
            cout << "Insert Coordinates:";
            cin >> x >> y;
            // cout << '\n';
            // cin.get();

            toLower(regionType);

            if (!strcmp(regionType, "line graph")) M.getLineGraphs()[index].addCity(x, y);
            else if (!strcmp(regionType, "general graph")) M.getGeneralGraphs()[index].addCity(x, y);
            else if (!strcmp(regionType, "complete graph")) M.getCompleteGraphs()[index].addCity(x, y);
            else if (!strcmp(regionType, "tree")) M.getTrees()[index].addCity(x, y);
            else if (!strcmp(regionType, "dag")) M.getDAGs()[index].addCity(x, y);
            else cout << "Typo! Try again.\n";
        }

        if (!strcmp(command, "add street"))
        {
            cout << "Insert Region Type (Line/ General/ Complete Graph, Tree or DAG):";
            cin.getline(regionType, maxStr);
            cout << "Insert Index of Region:";
            cin >> index;
            cout << "Insert Indexes of the Two Cities:";
            cin >> A >> B;
            // cout << '\n';
            // cin.get();

            toLower(regionType);

            if (!strcmp(regionType, "general graph")) M.getGeneralGraphs()[index].addStreet(A, B);
            else if (!strcmp(regionType, "tree")) M.getTrees()[index].addStreet(A, B);
            else if (!strcmp(regionType, "dag")) M.getDAGs()[index].addStreet(A, B);
            else cout << "Typo! Try again.\n";
        }

        if (!strcmp(command, "print shortest path"))
        {
            cout << "Insert Region Type (Line/ General/ Complete Graph, Tree or DAG):";
            cin.getline(regionType, maxStr);
            cout << "Insert Index of Region:";
            cin >> index;
            cout << "Insert Indexes of the Two Cities:";
            cin >> A >> B;
            // cout << '\n';
            // cin.get();

            toLower(regionType);

            if (!strcmp(regionType, "line graph")) cout << M.getLineGraphs()[index].getShortestPath(A, B) << " kilometers";
            else if (!strcmp(regionType, "general graph")) cout << M.getGeneralGraphs()[index].getShortestPath(A, B) << " kilometers";
            else if (!strcmp(regionType, "complete graph")) cout << M.getCompleteGraphs()[index].getShortestPath(A, B) << " kilometers";
            else if (!strcmp(regionType, "tree")) cout << M.getTrees()[index].getShortestPath(A, B) << " kilometers";
            else if (!strcmp(regionType, "dag")) cout << M.getDAGs()[index].getShortestPath(A, B) << " kilometers";
            else cout << "Typo! Try again.\n";
        }

        cin.getline(command, maxStr);
    }

    cout << "Program exited normally.";

    return 0;
}