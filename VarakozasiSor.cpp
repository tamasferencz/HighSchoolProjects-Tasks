/* STATIKUS VARAKOZASI SOR */
#include <iostream>

#define MAX_HOSSZ 100

using namespace std;

int elso = 0, utolso = -1;
float vsor[MAX_HOSSZ];

void letrehoz()
{

    int n;
    elso = 0;
    utolso = -1;

    do
    {
        cout << endl
             << ">>>Add meg az elemek szamat ";
        cin >> n;
    } while (n > MAX_HOSSZ);

    while (utolso < n - 1)
    {
        utolso++;
        cout << "Sor[" << utolso << "]= ";
        cin >> vsor[utolso];
    }

    cout << endl
         << ">>> A sor letrehozva" << endl;
}

void kiiras()
{
    if (utolso < elso)
        cout << endl
             << ">>>A sor ures! " << endl;
    else
    {
        cout << ">>>A sor elemei: \n";
        while (elso <= utolso)
        {
            cout << vsor[elso] << " ";
            elso++;
        }
    }
}

void beszuras()
{
    float elem;

    if (utolso == MAX_HOSSZ - 1)
        cout << ">>>A sor tele van!";
    else
    {
        cout << endl
             << ">>>Add meg az elemet: ";
        cin >> elem;

        utolso++;
        vsor[utolso] = elem;

        cout << ">>>Az elem beszurva!" << endl;
    }
}

void torles()
{

    if (utolso < elso)
        cout << ">>>A verem ures!";
    else
        elso++;
    cout << ">>>Az elso elem torolve! ";
}

int main()
{
    short menu;

    do
    {
        cout << endl;
        cout << "--------------------MENU--------------------" << endl;
        cout << "*          1. Sor letrehozasa!             *" << endl;
        cout << "*          2. Sor kiirasa!                 *" << endl;
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
