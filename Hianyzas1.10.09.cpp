#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cout << "n=";
    cin >> n;
    int a[n][n], b[n][n], c[n][n];

    srand(time(0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 90 + 10;
            b[i][j] = a[i][j] / 10;
            c[i][j] = a[i][j] % 10;
        }

    cout << "Az eredeti matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    cout << "Az elso szamjegyek matrixa: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }

    cout << "Az masodik szamjegyek matrixa: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }

    return 0;
}
