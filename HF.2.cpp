/* K. p. a. feltolt egy nxm-es matrixot 0-100 kozotti veletlenszeru szamokkal, majd 
beker egy 0-(n-1) kozotti indexet es kitorli a matrix adott sorat.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    int n, m, ind;

    cout << "Add meg az n-et: ";
    cin >> n;
    cout << "Add meg az m-et: ";
    cin >> m;
    cout << "Add meg az indexet: ";
    cin >> ind;

    int v[n][m];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            v[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(3)<< v[i][j];
        }
        cout << endl;
    }
    
    cout << endl;

    for (int i = 0; i <= m; i++)
    {
        v[ind][i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(3)<< v[i][j];
        }
        cout << endl;
    }
    
    return 0;
}