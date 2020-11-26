/*Egy negyzetes matrixban csereljuk meg a k-ik sort az m.-ik oszloppal*/

/*Toltsunk fel egy negyzetes matrixot a kovetkezo keppen: A foatlo elemei legyenek 0-ak,
a foatlo folotti elemek legyenek 1-ek, es a foatlo alatti elemek legyenek 2-*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    int n, m, k;

    cout << "Add meg az n-et: ";
    cin >> n;
    cout << "Add meg a k-t:";
    cin >> k;
    cout << "Add meg a m-t:";
    cin >> m;

    int v[n][n];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(3) << v[i][j];
        }
        cout << endl;
    }

    return 0;
}