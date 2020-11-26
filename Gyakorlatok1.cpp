#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{

    int n, s, a;

    cout << "n= ";
    cin >> n;

    srand(time(NULL));

    int v[n];

    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 100;
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                s = v[j];
                v[j] = v[j + 1];
                v[j + 1] = s;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}