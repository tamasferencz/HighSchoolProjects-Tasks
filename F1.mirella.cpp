#include <iostream>

using namespace std;

unsigned short szamj_ossz(unsigned int a)
{
    //cout << "Szamjegyeinek oszzege a(z) " << a << " nak/nek = ";
    unsigned short x = 1;
    for (unsigned int i = 0; i <= a; i++)
    {
        x += a % 10;
        a = a / 10;
    }
    return x;
}

unsigned short levagas(unsigned int a)
{
    //cout << "A(z) " << a << " utolso betuju nelkul = ";
    a = a / 10;
    return a;
}

unsigned short nulla_kereses(unsigned int a)
{
    unsigned short x = 0;
    for (unsigned int i = 0; i <= a; i++)
    {
        if (szamj_ossz(a) == szamj_ossz(a / 10))
        {
            x++;
        }
        a = a / 10;
    }
    return x;
}

int main()
{
    cout << szamj_ossz(1234) << endl;
    cout << levagas(1234) << endl;
    cout << nulla_kereses(102030) << endl;

    return 0;
}