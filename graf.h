#pragma once
#include<iostream>
#include<string.h>
#include<vector>



using namespace std;


class graf
{
    int nr_noduri;
    vector<int> *nod;

public:

    graf(int n = 0);

    ~graf() { delete[]this->nod;}

    void adauga_muchie(int n1, int n2);

    graf(const graf& gr);

    friend ostream& operator <<(ostream& out, const graf& gr);

    void BFS(int ni);

    void DFS(int ni, int* viz=nullptr, int main=1);

    void matrice_drumuri();

    void componente_conexe();

    void graf_conex_questionmark();

    friend graf operator +(graf& gr1, graf& gr2);





};