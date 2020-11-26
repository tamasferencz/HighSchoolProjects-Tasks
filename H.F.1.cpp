#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int n, m, legn;

    cout << "Add meg az n-et: ";
    cin >> n;
    cout << "Add meg az m-et: ";
    cin >> m;

    int v[n][m];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            v[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j] << "  ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        legn = v[i][0];
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] > legn)
            {
                legn = v[i][j];
            }
        }
        cout << "Legnagyobb a(z) " << i << " sorban: " << legn;
        cout << endl;
    }

    for (int j = 0; j < m; j++)
    {
        legn = v[0][j];
        for (int i = 0; i < n; i++)
        {
            if (v[i][j] > legn)
            {
                legn = v[i][j];
            }
        }
        cout << "Legnagyobb a(z) " << j << " oszlop: " << legn;
        cout << endl;
    }

    return 0;
}