/* Adott egy egesz szamokat tartalmazo lista. Hozzunk letre ket listat ugy,
hogy az elso tartalmazza a paros szamokat, mig a masodik a paratlan szamokat.
*/
#include <iostream>
#include <cstring>

#define MAX_HOSSZ 100

using namespace std;

void letrehoz(int lista[], int &n)
{
    do
    {
        cout << "Add meg az elemek szamat: ";
        cin >> n;
    } while (n > 100);

    for (int i = 0; i < n; i++)
    {
        cout << "lista[" << i << "]=";
        cin >> lista[i];
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

void beszur(int lista[], int &n, int elem)
{

    if (n == MAX_HOSSZ)
    {
        cout << "A lista tele van!" << endl;
    }
    else
    {
        lista[n] = elem;
        n++;
    }
    cout << endl;
}

int main()
{
    int lista[MAX_HOSSZ];
    int paros[MAX_HOSSZ];
    int paratlan[MAX_HOSSZ];

    int n = 0, m = 0, k = 0;

    letrehoz(lista, n);
    kiir(lista, n);

    for (int i = 0; i < n; i++)
    {
        if (lista[i] % 2 == 0)
        {
            beszur(paros, m, lista[i]);
        }
        else
        {
            beszur(paratlan, k, lista[i]);
        }
    }
    cout << "Paros lista: ";
    kiir(paros, m);
    cout << "Paratlan lista: ";
    kiir(paratlan, k);

    return 0;
}