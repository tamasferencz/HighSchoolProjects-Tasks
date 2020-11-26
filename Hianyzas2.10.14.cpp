#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n;

    cout << "n=";
    cin >> n;

    int a[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = min(i, j);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(3) << a[i][j];
        cout << endl;
    }

    return 0;
}
