/*Adott egy graf, amelyet szomszedsagi matrixal abrazolunk. Irjunk prgramot, amely
torli egy adott graf csomopontjat*/

#include <iostream>
#include <fstream>

using namespace std;

#define MAX_N 100

int n;
int v[MAX_N][MAX_N];
int b[MAX_N][MAX_N];

void Beolvas()
{
    ifstream be("szomszedsagi.txt");

    be >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            be >> v[i][j];
        }
    }

    be.close();
}

void Kiir()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void torles()
{
    int k;

    cout << "Add meg a torlendo csucsot: ";
    cin >> k;

    for (int i = 0; i < n; i++)
    {
        if (i == k)
        {
            i++;
        }

        for (int j = 0; j < n; j++)
        {
            if (j == k)
            {
                j++;
            }

            if (i != k && j != k)
            {
                b[i][j] = v[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Beolvas();
    cout << endl;
    Kiir();
    cout << endl;
    torles();
    return 0;
}