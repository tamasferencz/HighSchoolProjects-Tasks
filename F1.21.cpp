/*Ket matrixot csak akkor adhatunk ossze , ha a matrixok sora es 
oszlopa megeggyezik*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    int n, m;

    cout << "Add meg az n-et: ";
    cin >> n;
    cout << "Add meg az m-et: ";
    cin >> m;

    int a[n][m];
    int b[n][m];
    int c[n][m];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % 100;
            b[i][j] = rand() % 100;
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    cout << "Az a matrix: " << endl;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(3) << a[i][j];
        }
        cout << endl;
    }

    cout << endl;
    cout << "Az b matrix: " << endl;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(3) << b[i][j];
        }
        cout << endl;
    }

    cout << endl;
    cout << "Az a+b matrix: " << endl;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(4) << c[i][j];
        }
        cout << endl;
    }

    return 0;
}