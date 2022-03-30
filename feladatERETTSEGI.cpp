#include <iostream>

using namespace std;

int main()
{
    int n = 250887;
    int x = 0;
    int m = 0;
    int p = 1;
    int cn;

    while (x < 10)
    {
        cn = n;

        while (cn != 0)
        {
            int c = cn % 10;
            cn = cn / 10;
            if (c == x)
            {
                m = c * p + m;
                p = p * 10;
            }
        }
        x = x + 2;
    }
    cout << "M= " << m << endl;
}