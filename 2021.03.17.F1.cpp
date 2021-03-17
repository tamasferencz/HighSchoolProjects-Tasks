#include <iostream>
#include <algorithm>

using namespace std;

unsigned int s2(unsigned int p)
{
    int x = 0;
    while (p > 0)
    {
        if (p % 10 == 5)
        {
            x++;
        }
        p /= 10;
    }
    return x;
}

int main()
{
    unsigned int szam, y = 0;
    cout << "Adj meg egy szamot: ";
    cin >> szam;
    s2(szam);
    while (szam != 0)
    {
        cout << "Adj meg egy szamot: ";
        cin >> szam;
        s2(szam);
        y += s2(szam);
    }
    cout << y << endl;

    return 0;
}