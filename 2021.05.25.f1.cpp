#include <iostream>

using namespace std;

int f(int n)
{
    int c;
    if (n != 0)
    {
        if (n % 2 == 1)
        {
            c = 1 + f(n / 2);
        }
        else
        {
            c = f(n / 2);
        }
        cout << n % 2;
        return c;
    }
    else
    {
        return 0;
    }
}

void v(long int n)
{
    if (n != 0)
    {
        if (n % 2 != 0)
        {
            cout << n % 10;
        }
        v(n / 10);
        if (n % 2 == 0)
        {
            cout << n % 10;
        }
    }
    else
    {
        cout << endl;
    }
}

int k(int n, int y)
{
    if (n != 0)
    {
        y = y + 1;
        return y + k(n - 1, y);
    }
    else
    {
        return 0;
    }
}

long h(long n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        if (n % 10 == 0)
        {
            return h(n / 10);
        }
        else
        {
            return (n % 10) * h(n / 10);
        }
    }
}

int g(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
        return 2 * g(n - 1) + 2 * g(n - 2);
}

void l(long n)
{
    if (n > 9)
    {
        cout << n / 100;
        l(n / 10);
    }
}

int main()
{
    cout << f(12) << endl;
    v(12345);
    cout << endl;
    cout << k(3, 1) << endl;
    cout << h(4063) << endl;
    cout << g(3) << endl;
    l(12345);

    return 0;
}