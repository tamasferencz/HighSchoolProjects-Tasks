#include <iostream>

using namespace std;

void nule(int v[], int n)
{
    int x = n;
    for (int j = x; j < 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0)
            {
                int s = v[x - 1];
                v[x - 1] = v[i];
                v[i] = s;
            }
        }
        x--;
    }
}

int main()
{
    int v[6] = {12, -3, 0, 0, -8};
    nule(v, 6);

    return 0;
}