/*Ket matrixot csak akkor adhatunk ossze , ha a matrixok sora es 
oszlopa megeggyezik*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    int n, m, x, y;

    cout << "Add meg az n-et: ";
    cin >> n;
    cout << "Add meg az m-et: ";
    cin >> m;
    cout << endl;
    cout << "Add meg az x-et: ";
    cin >> x;
    cout << "Add meg az y-et: ";
    cin >> y;

    int a[n][m];
    int b[x][y];
    int c[n][m];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            b[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int v = 0; v < m; v++)
            {
                c[i][j] = c[i][j] + a[i][v] * b[v][j];
            }
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
    cout << "A b matrix: " << endl;
    cout << endl;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << setw(3) << b[i][j];
        }
        cout << endl;
    }

    cout << endl;
    cout << "Az a*b matrix: " << endl;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(6) << c[i][j];
        }
        cout << endl;
    }

    return 0;
}