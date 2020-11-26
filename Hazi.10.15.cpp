/* Készíts programot, amely feltölt és kiír a képernyőre 
egy nxn-es mátrixot, amely az alábbi minta alapján épül fel:

n=5
 
1   1   1   1   1
1   2   2   2   1
1   2   3   2   1
1   2   2   2   1
1   1   1   1   1 
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n, k = 0;

    cout << "n=";
    cin >> n;

    int a[n][n];
    for (int k = 0; k < n / 2; k++)
    {
        for (int j = k; j < n - k; j++)
        {
            a[0][j] = k + 1;
            a[n - k - 1][j] = k + 1;
        }

        for (int i = k + 1; i < n - k; i++)
        {
            a[i][0] = k + 1;
            a[i][n - k - 1] = k + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(3) << a[i][j];
        cout << endl;
    }

    return 0;
}
