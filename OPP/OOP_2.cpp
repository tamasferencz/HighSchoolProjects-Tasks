#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Focista.h";

using namespace std;

void Szimulal(Focista f)
{

    int van_meccs, helyzet, gol, edz, ora;
    srand(time(0));
    for (int nap = 1; nap <= 30; nap++)
    {
        van_meccs = rand() % 3;
        if (van_meccs == 1)
        {
            f.jatszik();
            cout << "A(z) " << nap << ". nap meccs van!" << endl;
            helyzet = rand() % 21;
            for (int h = 1; h <= helyzet; h++)
            {
                gol = rand() % 3;
                if (gol == 2)
                {
                    cout << f.getNev() << " goool!" << endl;
                    f.goltRug();
                }
                if (gol == 1)
                {
                    cout << f.getNev() << " kapufa!" << endl;
                }
            }
        }
        else
        {
            if (van_meccs == 2)
            {
                cout << "Elhalasztott meccs a " << nap << ". napon" << endl;
            }
            edz = rand() % 2;
            if (edz)
            {
                ora = rand() % 4 + 1;
                cout << f.getNev() << " " << ora << " orat edzett" << endl;
                f.edz(ora);
            }
        }
    }
    f.adatok();
    cout << "Fizetes: " << f.fizetes() << endl;
}

int main()
{
    Focista f1("Lakatos Ronaldo", 1027);
    Szimulal(f1);

    return 0;
}