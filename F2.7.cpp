/*K. p. a, amely feltolt egy n dimenzios negyzetes matrixot a kovetkezo minta alapjan */

#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    int n, szam=0;

    cout << "n= ";
    cin >> n;

    int v[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v[i][j] = szam+1;
            szam++;
            if(szam == 3){
                szam = 0;
            }
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