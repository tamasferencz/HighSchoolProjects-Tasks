#include <iostream>

#define MAX_N 100

using namespace std;

int v[MAX_N];
int S;
int db = 0;

void Inicializal(int k)
{
    v[k] = 0;
}

void Beallit(int k)
{
    v[k]++;
}

bool Letezik(int k)
{
    return (v[k] <= S);
}

bool Jo(int k)
{
    return true;
}

bool Megoldas(int k)
{
    int ossz = 0;
    for (int i = 0; i <= k; i++)
    {
        ossz = ossz + v[i];
    }
    if (ossz == S)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Kiir(int k)
{
    for (int i = 0; i <= k; i++)
        cout << v[i] << "+";
    cout << "\b"
         << " " << endl;
}

void Backtracking()
{
    int i = 0;
    Inicializal(i);
    while (i > -1)
    {
        Beallit(i);
        if (Letezik(i))
        {
            if (Jo(i))
                if (Megoldas(i))
                {
                    Kiir(i);
                    db++;
                }
                else
                {
                    i++;
                    Inicializal(i);
                }
        }
        else
            i--;
    }
}

int main()
{
    cout << "S=";
    cin >> S;
    Backtracking();
    cout << db << "megoldas van!";

    return 0;
}