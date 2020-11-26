/*Ket matrixot csak akkor adhatunk ossze , ha a matrixok sora es 
oszlopa megeggyezik*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    int n, m, x, y, ossz;

    cout << "Add meg az n-et: ";
    cin >> n;
    cout << "Add meg az m-et: ";
    cin >> m;

    int a[n][m];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        ossz = 0;
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % 100;
            ossz += a[i][j];
        }
        cout << "Sorosszeg= " << ossz << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(3) << a[i][j];
        }
        cout << endl;
    }

    for (int j = 0; j < m; j++)
    {
        ossz = 0;
        for (int i = 0; i < n; i++)
        {
            ossz += a[i][j];
        }
        cout << "Oszloposszeg= " << ossz << endl;
    }

    return 0;
}