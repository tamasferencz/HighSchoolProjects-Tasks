#include <iostream>
#include <fstream>

using namespace std;

#define MAX_N 100

int n;
int v[MAX_N];

void Beolvas()
{
    ifstream be("osvektor.txt");

    be >> n;

    for (int i = 0; i < n; i++)
    {
        be >> v[i];
    }

    be.close();
}

void Kiir()
{
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}

void osvektor()
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " - " << v[i] << endl;
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            cout << endl;
            cout << i + 1 << " <-- Ez a csucspont a gyoker!" << endl;
            cout << endl;
        }
    }
}

void levelek()
{
    int y = 0;
    bool x = true;

    for (int i = 1; i <= n; i++)
    {
        x = true;
        for (int j = 0; j < n; j++)
        {
            if (i == v[j])
            {
                x = false;
            }
        }
        if (x)
        {
            y++;
            cout << i << "<-- Ez a csucs level!" << endl;
        }
    }
    cout << "A levelek szama: " << y << endl;
}

void kGyerekek()
{
    int x;

    cout << "Adj meg egy csucsot: ";
    cin >> x;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            cout << i + 1 << "<-- A csucsnak az egyik gyereke!" << endl;
        }
    }
}

void szulo()
{
    int x;

    cout << "Adj meg egy csucsot: ";
    cin >> x;
    cout << endl;

    cout << v[x - 1] << "<-- Ez a csucs szuleje!" << endl;
}

void szint()
{
    int levelek[MAX_N];
    int j = -1;
    int magassag = 0, maxi = 0;

    int y = 0;
    bool x = true;

    for (int i = 1; i <= n; i++)
    {
        x = true;
        for (int j = 0; j < n; j++)
        {
            if (i == v[j])
            {
                x = false;
            }
        }
        if (x)
        {
            y++;
            j++;
            levelek[i] = i + 1;
        }
    }

    for (int i = 0; i <= j; i++)
    {
        while (levelek[i] !=)
    }
}

int main()
{
    Beolvas();
    cout << endl;
    Kiir();
    cout << endl;
    cout << endl;
    osvektor();
    cout << endl;
    levelek();
    cout << endl;
    kGyerekek();
    cout << endl;
    szulo();
    cout << endl;
    szint();
    return 0;
}