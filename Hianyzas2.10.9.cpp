#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(0));
    int szam = rand() % 90000 + 10000;
    int _szam = 0;
    int a[5][5];

    cout << "A szam: " << szam << endl;

    while (szam != 0)
    {
        _szam = _szam * 10 + szam % 10;
        szam = szam / 10;
    }
    szam = _szam;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            if (i == 0)
            {
                a[i][j] = szam % 10;
                szam = szam / 10;
            }
            else if (j != 0)
                a[i][j] = a[i - 1][j - 1];
            else
                a[i][j] = a[i - 1][4];
        }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}
