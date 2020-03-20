#include"graf.h"

using namespace std;

int main()
{
    ///vector<int> v;
    ///v.push_back(3);
    ///v.size();

    graf g1(12);

    g1.adauga_muchie(1, 2);
    g1.adauga_muchie(1, 4);
    g1.adauga_muchie(2, 3);
    g1.adauga_muchie(2, 5);
    g1.adauga_muchie(4, 5);
    g1.adauga_muchie(4, 6);
    g1.adauga_muchie(5, 7);
    g1.adauga_muchie(7, 8);
    g1.adauga_muchie(8, 9);
    g1.adauga_muchie(7, 9);
    g1.adauga_muchie(11, 10);

    g1.BFS(1);

    cout << endl << endl;

    g1.DFS(1);

    cout << endl << endl;

    g1.graf_conex_questionmark();

    cout << endl << endl;


    g1.matrice_drumuri();


    cout << endl << endl;


    g1.componente_conexe();



    cout << endl << endl;

    graf g2(g1);
    g2.adauga_muchie(5, 3);
    cout << g2;



    cout << endl << endl;

    graf g3(4);

    g3.adauga_muchie(1, 2);
    g3.adauga_muchie(2, 3);
    g3.adauga_muchie(3, 4);
    g3.adauga_muchie(1, 4);

    g3.BFS(1);

    cout << endl << endl;

    g3.graf_conex_questionmark();


    cout << endl;

    graf g4(5), g5(5);

    g4.adauga_muchie(1, 5);
    g4.adauga_muchie(1, 3);
    g4.adauga_muchie(3, 4);
    g4.adauga_muchie(2, 5);


    g5.adauga_muchie(1, 5);
    g5.adauga_muchie(1, 4);
    g5.adauga_muchie(3, 4);
    g5.adauga_muchie(3, 5);

    cout << g4 + g5;

















    return 0;
}
