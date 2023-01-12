#include "Termek.h"

using namespace std;

int main()
{
    int i;
    termek a_kezelo;

    while (1)
    {
        cout << "\n  +---------------------------------+";
        cout << "\n  |   Mit szeretne tenni?           |";
        cout << "\n  |                                 |";
        cout << "\n  |1: Adjon hozzá egy új tárgyat.   |";
        cout << "\n  |2: Töröljön egy terméket.        |";
        cout << "\n  |3: Adjon el terméket/termékeket. |";
        cout << "\n  |4: Töltse fel az árut.           |";
        cout << "\n  |5: Mutassa ki a termékeket.      |";
        cout << "\n  |6: Kilép!                        |";
        cout << "\n  +---------------------------------+" << endl;
        cout << "\n\n Válasszon egy számot:";
        cin >> i;

        switch (i)
        {
        case 1:
        {
            a_kezelo.hozzaad_();
            break;
        }
        case 2:
        {
            a_kezelo.torol_();
            break;
        }
        case 3:
        {
            a_kezelo.elad_();
            break;
        }
        case 4:
        {
            a_kezelo.feltolt_();
            break;
        }
        case 5:
        {
            a_kezelo.kijelez_();
            break;
        }

        case 6:
        {
            cout << "Rendszer leallitva!" << endl;
            break;
        }
        }
        if (i == 6)
        {
            break;
        }
    }
    return 0;
}