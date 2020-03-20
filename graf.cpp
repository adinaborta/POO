#include "graf.h"

using namespace std;

graf::graf(int n)
{
    this->nr_noduri = n;
    this->nod = new vector<int>[n];
}

void graf::adauga_muchie(int n1, int n2)
{
    this->nod[n1-1].push_back(n2); 
    this->nod[n2-1].push_back(n1);
}

graf::graf(const graf& gr)
{
    this->nr_noduri = gr.nr_noduri;
    this->nod = new vector<int>[gr.nr_noduri];
    for (int i = 0; i < this->nr_noduri; i++)
    {
        this->nod[i].assign(gr.nod[i].begin(), gr.nod[i].end());
    }

}

ostream& operator <<(ostream& out, const graf& gr)
{
    for (int j = 0; j < gr.nr_noduri; j++)
    {
        if (size(gr.nod[j]) > 0)
        {
            out << j + 1 << ": ";
            for (int i = 0; i < size(gr.nod[j]); i++)
                out << gr.nod[j][i] << " ";
        out << endl;
        }
    }
    return out;
}

void graf::BFS(int ni)
{
    int v[100], viz[100], p, u, el;

    for (int i = 0; i < this->nr_noduri; i++)
    {
        viz[i] = 0;
    }

    v[0]=ni;
    viz[ni-1] = 1;
    p = 0;
    u = 0;

    while (p <= u)
    {
        el = v[p];

        for (int i = 0; i < size(this->nod[el-1]); i++)
        {
            if (viz[this->nod[el-1][i]-1] == 0)
            {
                u++;
                v[u]=this->nod[el - 1][i];
                viz[this->nod[el - 1][i]-1] = 1;
            }
        }

        p++;
    }


    for (int i = 0; i < p; i++)
    {
        cout << v[i] << " ";
    }


}

void graf::DFS(const int ni, int* viz, int main)
{
    if (!viz)
    {

        viz = new int[this->nr_noduri];

        for (int i = 0; i < nr_noduri; i++)
        {
            viz[i] = 0;
        }
    }

        viz[ni-1] = 1;

        
        if(main!=2)
            cout << ni<<" ";

        for (int i = 0; i < size(this->nod[ni - 1]); i++)
        {
            if (viz[nod[ni - 1][i] - 1] == 0)
                if(main!=2)
                    DFS(nod[ni - 1][i], viz, 0);
                else
                    DFS(nod[ni - 1][i], viz, 2);
        }

        if (main == 1)
        {
            delete[]viz;
        }
}

void graf::matrice_drumuri(){

    int* viz = new int[this->nr_noduri];

    for (int i = 0; i < this->nr_noduri; i++)
    {
        viz[i] = 0;
    }

    int ok = 0, i=1;

    while(ok==0)
    {
        DFS(i, viz, 2);
        ok = 1;
        for (int j = 0; j < this->nr_noduri; j++)
        {
            if (viz[j] != 0)
                viz[j]++;
            else
            {
                i = j+1;
                ok = 0;
            }
        }
    }

    for (int l = 0; l <= this->nr_noduri; l++)
    {
        for (int c = 0; c <= this->nr_noduri; c++)
        {
            if (viz[l] == viz[c])
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }

        cout << endl;
    }

    delete[] viz;

}

void graf::componente_conexe()
{
    int* viz = new int[this->nr_noduri];

    for (int i = 0; i < this->nr_noduri; i++)
    {
        viz[i] = 0;
    }

    int ok = 0, i = 1;

    cout << "COMPONENTELE CONEXE SUNT:" << endl;

    while (ok == 0)
    {
        DFS(i, viz, 2);
        ok = 1;

        for (int j = 0; j < this->nr_noduri; j++)
        {
            if (viz[j] == 1)
                cout << j + 1 << " ";
            if (viz[j] != 0)
                viz[j]++;
            else
            {
                i = j + 1;
                ok = 0;
            }
        }

        cout << endl;
    }

    delete[]viz;

}

void graf::graf_conex_questionmark()
{
    int* viz = new int[this->nr_noduri];

    for (int i = 0; i < this->nr_noduri; i++)
    {
        viz[i] = 0;
    }

    int ok = 1, i = 0;

    if (this->nr_noduri > 0)
    {
        DFS(1, viz, 2);
        while (ok == 1 && i < this->nr_noduri)
        {
            if (viz[i] == 0)
                ok = 0;
            i++;
        }
    }

    else
        ok = 0;

    if (ok == 1)
        cout << "GRAFUL ESTE CONEX";
    else
        cout << "GRAFUL NU ESTE CONEX";




    delete[]viz;


}

graf operator +(graf& gr1, graf& gr2)
{
    graf gr_suma(gr1);

    for (int i = 0; i < gr2.nr_noduri; i++)
    {
        for (int j = 0; j < size(gr2.nod[i]);j++)
        {
            if(count(gr_suma.nod[i].begin(), gr_suma.nod[i].end(), gr2.nod[i][j])==0)
                gr_suma.nod[i].push_back(gr2.nod[i][j]);
        }
    }
     
    return gr_suma;

}






