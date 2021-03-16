#include <iostream>
#include <algorithm>

using namespace std;

void s1(unsigned int &a, unsigned int &b)
{
    swap(a, b);
}

unsigned int s2(unsigned int v[100], unsigned int p, unsigned int q)
{
    if (p > q)
    {
        s1(p, q);
    }
    else
    {
        for (p; p < q; p++)
        {
            if (v[p] % 5 == 0)
            {
                return p;
            }
        }
    }
    return -1;
}

int main()
{
    unsigned int v[100];
    cout << s2(v, 5, 25) << endl;

    return 0;
}