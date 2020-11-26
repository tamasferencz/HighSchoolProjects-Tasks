#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    int n,szam=1;

    cout << "n= ";
    cin >> n;

    int v[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v[i][j] = i * j;
        }

    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(3)<< v[i][j];
        }
        cout << endl;
    }

    return 0;
}