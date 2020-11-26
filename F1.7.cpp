/*K. p. a, egy nxm-es ket dimenzios tombot feltolt az
elso n*m termeszetes szam kobevel.*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){

    int n,m, szam=1;

    cout << "n= ";
    cin >> n;
    cout << "m= ";
    cin >> m;

    int v[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            v[i][j] = pow(szam,3);
            szam++;
        }

    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(7)<< v[i][j];
        }
        cout << endl;
    }

    return 0;
}