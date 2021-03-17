#include <iostream>
#include <algorithm>

using namespace std;

unsigned short inter(unsigned short v[100], unsigned short x)
{
    int db = 0;
    short y = v[x - 1];
    short z = v[0];
    if (y > z)
    {
        swap(y, z);
    }
    for (int i = 0; i < x; i++)
    {
        if (v[i] > z && v[i] < y)
        {
            db++;
        }
    }
    return db;
}

int main()
{
    unsigned short v[100], a;

    cout << inter(v, 25);

    return 0;
}