// PERMUTACIOK
#include <iostream>
#include <fstream>

using namespace std;

#define MAX_N 100

int v[MAX_N];
int n;

void Beallit(int k, int i)
{
    v[k] = i;
}

void Kiir(int k)
{
    for (int i = 0; i < k; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

bool Megfelel(int k)
{
    for (int i = 0; i <= k; i++)
    {
        if (v[i] == v[k])
        {
            return false;
        }
    }
    return true;
}

bool Megoldas(int k)
{
    return (k + 1 == n);
}

void Backtracking(int szint)
{
    if (Megoldas(szint))
    {
        Kiir(szint);
    }
    else
    {
        for (int i = 0; i <= n; i++)
        {
            Beallit(szint, i);
            if (Megfelel(szint))
            {
                Backtracking(szint + 1);
            }
        }
    }
}

int main()
{
    cout << "n= ";
    cin >> n;
    Backtracking(0);

    return 0;
}