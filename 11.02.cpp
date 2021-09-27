#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    int n, m, legk, legn, osszeg;
    float atlag, ossz = 0, x = 0;

    cout << "n=";
    cin >> n;
    cout << "m=";
    cin >> m;
    c int v[n][m];

    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            v[i][j] = rand() % 100;
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(3) << v[i][j];
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        x = 0;
        ossz = 0;
        for (int j = 0; j < m; j++)
        {
            ossz = ossz + v[i][j];
            x++;
        }
        atlag = ossz / x;
        cout << i << ". Sor Atlaga= " << atlag << endl;
    }

    cout << endl;

    for (int j = 0; j < m; j++)
    {
        x = 0;
        ossz = 0;
        for (int i = 0; i < n; i++)
        {
            ossz = ossz + v[i][j];
            x++;
        }
        atlag = ossz / x;
        cout << j << ". Oszlop Atlaga= " << atlag << endl;
    }

    cout << endl;

    legn = v[0][0];
    legk = v[0][0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][j] > legn)
            {
                legn = v[i][j];
            }
            if (v[i][j] < legk)
            {
                legk = v[i][j];
            }
        }
    }

    cout << "A legnagyobb a matrixbol a " << legn << "!" << endl;
    cout << "A legkisebb a matrixbol a " << legk << "!" << endl;

    cout << endl;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            osszeg = osszeg + v[i][j];
        }
    }

    cout << "A matrix elemeinek osszege= " << osszeg;

    return 0;
}
