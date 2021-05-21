#include <iostream>

using namespace std;

unsigned int ossz(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n * n + ossz(n - 1);
    }
}

int main()
{
    cout << ossz(6) << endl;

    return 0;
}