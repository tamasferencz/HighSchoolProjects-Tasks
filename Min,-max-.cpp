/*K. p. a, feltolt egy nxm-es matrixot ketjegy veletlenszeru szamokkal 
es kiirja a legnagyobb es a legkisebb elem kozti kulombseget*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int n, m, legn, legk, kulonb;

    cout << "n=";
    cin >> n;
    cout << "m=";
    cin >> m;

    int a[n][m];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            a[i][j] = rand() % 90 + 10;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << setw(3) << a[i][j];
        cout << endl;
    }

    legn = a[0][0];
    legk = a[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] > legn)
            {
                legn = a[i][j];
            }
            if (a[i][j] < legk)
            {
                legk = a[i][j];
            }
        }
    }

    cout << endl;

    cout << "A legnagyobb: " << legn << endl;
    cout << "A legkisebb: " << legk << endl;

    kulonb = legn - legk;

    cout << "A legnagyobb es legkisebb elem kozti kulonbseg: " << kulonb << endl;

    return 0;
}