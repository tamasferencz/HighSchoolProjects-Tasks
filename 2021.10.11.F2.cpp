/*Hozzunk letre egy rendezett listat!*/

/* Adott egy egesz szamokat tartalmazo lista. Hozzunk letre ket listat ugy,
hogy az elso tartalmazza a paros szamokat, mig a masodik a paratlan szamokat.
*/
#include <iostream>
#include <cstring>

#define MAX_HOSSZ 100

using namespace std;

void beszur(int lista[], int &n, int poz, int elem)
{

    if (n == MAX_HOSSZ)
    {
        cout << "A lista tele van!" << endl;
    }
    else
    {
        n++;

        for (int i = n - 1; i >= poz; i--)
        {
            lista[i] = lista[i - 1];
        }
        lista[poz] = elem;
    }
    cout << endl;
}

void letrehoz(int lista[], int &n)
{
    int m;
    do
    {
        cout << "Add meg az elemek szamat: ";
        cin >> m;
    } while (m > MAX_HOSSZ);

    int elem, poz;

    for (int i = 0; i < m; i++)
    {
        cout << "Adk meg egy elemet: ";
        cin >> elem;
        for (int j = 0; j < i; j++)
        {
            if (elem <= lista[j])
            {
                poz = j;
            }
        }
        beszur(poz, elem);
    }
}

void kiir(int lista[], int n)
{
    if (n == 0)
    {
        cout << "A lista ures!" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << lista[i] << ",";
            cout << "\b"
                 << " ";
        }
    }
    cout << endl;
}

int main()
{
    int lista[MAX_HOSSZ];

    int n = 0;

    letrehoz(lista, n);
    kiir(lista, n);
    return 0;
}