/*STATIKUS LISTA*/
#include <iostream>
#include <cstring>

#define MAX_H 100

using namespace std;

unsigned int n = 0;
float lista[MAX_H];

/*ALPROGRAMOK*/

void letrehoz()
{
    do
    {
        cout << "Add meg az elemek szamat: ";
        cin >> n;
    } while (n > 100);

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "lista[" << i << "]=";
        cin >> lista[i];
    }
    cout << endl;
    cout << "----> A lista letrehozva!" << endl;
    cout << endl;
    cout << endl;
}

void kiir()
{
    if (n == 0)
    {
        cout << "A lista ures!" << endl;
    }
    else
    {
        cout << "A lista: ";
        for (int i = 0; i < n; i++)
        {
            cout << lista[i] << ",";
            cout << "\b"
                 << " ";
        }
    }
    cout << endl;
    cout << endl;
    cout << "----> A lista kiirva!" << endl;
    cout << endl;
    cout << endl;
}

void beszur()
{
    unsigned int poz;
    float elem;

    if (n == 0)
    {
        cout << "A lista ures!" << endl;
    }
    else
    {
        do
        {
            cout << "Add mega poziciot: ";
            cin >> poz;
        } while (poz > n || poz <= 0);
        poz--;
        cout << "Add meg az elemet: ";
        cin >> elem;
        n++;

        for (int i = n - 1; i >= poz; i--)
        {
            lista[i] = lista[i - 1];
        }
        lista[poz] = elem;

        cout << endl;
        cout << "----> Az elem beszurva!" << endl;
        cout << endl;
        cout << endl;
    }
}

void torles()
{
    unsigned int poz;
    float elem;

    if (n == 0)
    {
        cout << "A lista ures!" << endl;
    }
    else
    {
        do
        {
            cout << "Add meg a poziciot: ";
            cin >> poz;
        } while (poz > n || poz <= 0);

        poz--;

        for (int i = poz; i < n; i++)
        {
            lista[i] = lista[i + 1];
        }
        n--;

        cout << endl;
        cout << "----> Az elem torolve!" << endl;
        cout << endl;
        cout << endl;
    }
}

void keres()
{
    int kElem;
    bool kerElem = false;

    cout << "Add meg a keresett elemet: ";
    cin >> kElem;

    for (int i = 0; i < n; i++)
    {
        if (lista[i] == kElem)
        {
            kerElem = true;
            cout << "A keresett elem " << lista[i] << ", indexe pedig " << i << " !" << endl;
        }
    }

    if (kerElem == false)
    {
        cout << "Nincs olyan elem!" << endl;
    }

    cout << endl;
    cout << endl;
    cout << "----> Az elem megkeresve!" << endl;
    cout << endl;
    cout << endl;
}

void rendez()
{
    char rend[50];
    bool sorr = false;

    cout << "Add meg, hogy novekvo vagy csokkeno sorrendbe rendezze a lista elemeit: ";
    cin >> rend;

    if (strcmp(rend, "csokkeno") == 0)
    {
        sorr = true;
        for (int j = 0; j < n - 1; j++)
        {
            for (int i = j + 1; i < n; i++)
            {
                if (lista[i] > lista[j])
                {
                    float s = lista[i];
                    lista[i] = lista[j];
                    lista[j] = s;
                }
            }
        }
    }

    if (strcmp(rend, "novekvo") == 0)
    {
        sorr = true;
        for (int j = 0; j < n - 1; j++)
        {
            for (int i = j + 1; i < n; i++)
            {
                if (lista[i] < lista[j])
                {
                    float s = lista[i];
                    lista[i] = lista[j];
                    lista[j] = s;
                }
            }
        }
    }

    if (sorr == false)
    {
        cout << "Nem helyes tipusu sorrendet adott meg!" << endl;
    }
}

int main()
{
    short menu;

    do
    {
        cout << endl;
        cout << "+------------------------+" << endl;
        cout << "|          MENU          |" << endl;
        cout << "+------------------------+" << endl;
        cout << "|  1 - Lista letrehozas  |" << endl;
        cout << "|  2 - Lista kiiras      |" << endl;
        cout << "|  3 - Elem beszurasa    |" << endl;
        cout << "|  4 - Elem torlese      |" << endl;
        cout << "|  5 - Elem keresese     |" << endl;
        cout << "|  6 - Elemek rendezese  |" << endl;
        cout << "+------------------------+" << endl;
        cout << "|  0 - Kilepes           |" << endl;
        cout << "+------------------------+" << endl;
        cout << endl;
        cout << "Valassz muveletet: ";
        cin >> menu;

        switch (menu)
        {
        case 0:
            cout << endl;
            cout << "Kileptel!" << endl;
            cout << endl;
            break;
        case 1:
            letrehoz();
            break;
        case 2:
            kiir();
            break;
        case 3:
            beszur();
            break;
        case 4:
            torles();
            break;
        case 5:
            keres();
            break;
        case 6:
            rendez();
            break;
        default:
            cout << "Nincs ilyen menupont!" << endl;
            break;
        }

    } while (menu != 0);

    return 0;
}