#include <iostream>
#include <cmath>

using namespace std;

bool prim(unsigned int szam)
{
    if (szam == 0 || szam == 1)
    {
        return false;
    }
    else
    {
        for (unsigned int i = 2; i <= (unsigned int)sqrt(szam); i++)
        {
            if (szam % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int h(int a, int p)
{
    if (!prim(p) || a % p != 0)
    {
        return 0;
    }
    else
    {
        return 1 + h(a / p, p);
    }
}

int main()
{
    cout << h(32, 2) << endl;

    return 0;
}
