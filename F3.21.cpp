/*Ket matrixot csak akkor adhatunk ossze , ha a matrixok sora es 
oszlopa megeggyezik*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    int n, m, oszl = 0, atlag, x = 0;

    cout << "Add meg az n-et: ";
    cin >> n;
    cout << "Add meg az m-et: ";
    cin >> m;

    int a[n][m];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(3) << a[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            x = x + a[i][j];
        }
        cout << endl;
    }

    atlag = x / (n - 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "A(z) " << i << "-dik sor atlaga= " << atlag << endl;
        }
        cout << endl;
    }

    return 0;
}