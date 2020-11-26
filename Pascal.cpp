#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int szint;

    cout << "Add meg a Pascal haromszog szintjet: ";
    cin >> szint;

    unsigned long h[szint + 1][szint + 1];

    h[0][0] = 1;
    h[1][0] = 1;
    h[1][1] = 1;

    for (int i = 2; i < szint; i++)
    {
        h[i][0] = 1;
        h[i][i] = 1;
        for (int j = 1; j < i; j++)
            h[i][j] = h[i - 1][j - 1] + h[i - 1][j];
    }

    for (int i = 0; i < szint; i++)
    {
        cout << setw(2 * (szint - i));
        for (int j = 0; j < i + 1; j++)
            cout << h[i][j] << setw(szint / 5 + 2);
        cout << endl;
    }

    return 0;
}
