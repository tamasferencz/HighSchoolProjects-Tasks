/*Toltsunk fel egy negyzetes matrixot a kovetkezo keppen: A foatlo elemei legyenek 0-ak,
a foatlo folotti elemek legyenek 1-ek, es a foatlo alatti elemek legyenek 2-*/

#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Add meg az n-et: ";
    cin >> n;

    int v[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                v[i][j] = 0;
            }
            if (i < j)
            {
                v[i][j] = 1;
            }
            if (i > j)
            {
                v[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}