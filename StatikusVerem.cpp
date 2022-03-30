/* STATIKUS VEREM */
#include <iostream>

#define MAX_MELYSEG 100

using namespace std;

int csucs = -1;
float verem[MAX_MELYSEG];

void letrehoz()
{

    int n;
    csucs = -1;
    do
    {
        cout << endl
             << ">>>Add meg az elemek szamat ";
        cin >> n;
    } while (n > MAX_MELYSEG);

    while (csucs < n - 1)
    {
        csucs++;
        cout << "Verem[" << csucs << "]= ";
        cin >> verem[csucs];
    }

    cout << endl
         << ">>> A verem letrehozva" << endl;
}

void kiiras()
{
    if (csucs == -1)
        cout << endl
             << ">>>A verem ures! " << endl;
    else
    {
        cout << endl
             << ">>>A verem elemei: \n";
        while (csucs >= 0)
        {
            cout << "         " << verem[csucs] << endl;
            csucs--;
        }
    }
}

void beszuras()
{
    float elem;

    if (csucs == MAX_MELYSEG - 1)
        cout << ">>>A verem tele van!";
    else
    {
        cout << endl
             << ">>>Add meg az elemet: ";
        cin >> elem;

        csucs++;
        verem[csucs] = elem;

        cout << ">>>Az elem beszurva!" << endl;
    }
}

void torles()
{
    int pozicio;

    if (csucs == -1)
        cout << ">>>A verem ures!";
    else
        csucs--;
    cout << ">>>A csucs elem torolve! ";
}

int main()
{
    short menu;

    do
    {
        cout << endl;
        cout << "--------------------MENU--------------------" << endl;
        cout << "*          1. Verem letrehozasa!           *" << endl;
        cout << "*          2. Verem kiirasa!               *" << endl;
        cout << "*          3. Elem beszurasa!              *" << endl;
        cout << "*          4. Elem torlese!                *" << endl;
        cout << "*          0. Kilepes!                     *" << endl;
        cout << "--------------------------------------------" << endl;
        cout << endl;

        cout << "Valassz muveletet! ";
        cin >> menu;

        switch (menu)
        {
        case 0:
            cout << "Kileptel! ";
            break;
        case 1:
            letrehoz();
            break;
        case 2:
            kiiras();
            break;
        case 3:
            beszuras();
            break;
        case 4:
            torles();
            break;
        default:
            cout << "Nincs ilyen menupont! " << endl;
        }

    } while (menu != 0);

    return 0;
}
