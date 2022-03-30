/* STATIKUS VEREM */
#include <iostream>

#define MAX_MELYSEG 100

using namespace std;

int csucs = -1;
float verem[MAX_MELYSEG];

void letrehoz(int verem[], int &csucs)
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

void kiir(int verem[], int &csucs)
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

void beszur(int verem[], int &csucs, int elem)
{

    if (csucs == MAX_MELYSEG - 1)
        cout << ">>>A verem tele van!";
    else
    {

        csucs++;
        verem[csucs] = elem;
    }
}

void torol(int verem[], int &csucs)
{
    int pozicio;

    if (csucs == -1)
        cout << ">>>A verem ures!";
    else
        csucs--;
}

void attesz(int verem1[], int &csucs1, int verem2[], int &csucs2)
{
    beszur(verem2, csucs2, verem1[csucs1]);
    torol(verem1, csucs1);
}

int main()
{
    int verem1[MAX_MELYSEG];
    int verem2[MAX_MELYSEG];

    int csucs1 = -1, csucs2 = -1;
    int elem;

    letrehoz(verem1, csucs1);

    cout << "Add meg a torlendo elemet: ";
    cin >> elem;

    while (verem1[csucs1] != elem && csucs1 >= 0)
    {
        attesz(verem1, csucs1, verem2, csucs2);
    }

    if (csucs1 == -1)
    {
        cout << "Az elem nincs a veremben!" << endl;
    }
    else
    {
        torol(verem1, csucs1);
    }

    while (csucs2 >= 0)
    {
        attesz(verem2, csucs2, verem1, csucs1);
    }

    kiir(verem1, csucs1);

    return 0;
}
