#include <iostream>

using namespace std;

unsigned long long fordit(unsigned long long n)
{
    unsigned long long uj_n = 0;
    while (n != 0)
    {
        uj_n = uj_n * 10 + n % 10;
        n = n / 10;
    }
    return uj_n;
}

bool palindrom(unsigned long long n)
{
    /*if(n==fordit(n))
        return true;
    else
        return false;*/
    return (n == fordit(n));
}

void palindromok(unsigned long long n)
{
    cout << "A palindormok " << n << "-ig:" << endl;
    for (unsigned long long i = 1; i <= n; i++)
        if (palindrom(i))
            cout << i << ",";
    cout << "\b"
         << " " << endl;
}

unsigned short szamjegyek_szama(unsigned long long n)
{
    unsigned short db = 0;
    while (n != 0)
    {
        db++;
        n = n / 10;
    }
    return db;
}

unsigned long long hatvany(unsigned short a, unsigned short h)
{
    unsigned long long eredmeny = 1;
    for (unsigned short i = 1; i <= h; i++)
        eredmeny = eredmeny * a;
    return eredmeny;
}

bool Armstrong(unsigned long long n)
{
    unsigned long long uj_n = 0, h, rakt;
    rakt = n;
    h = szamjegyek_szama(n);
    while (n != 0)
    {
        uj_n = uj_n + hatvany(n % 10, h);
        n = n / 10;
    }
    if (rakt == uj_n)
        return true;
    else
        return false;
}

unsigned long long alakit_10_2(unsigned int n)
{
    unsigned long long uj_n = 0, hatvany = 1;
    while (n != 0)
    {
        uj_n = uj_n + (n % 2) * hatvany;
        hatvany = hatvany * 10;
        n = n / 2;
    }
    return uj_n;
}

unsigned int alakit_2_10(unsigned long long n)
{
    unsigned int uj_n = 0, hatvany = 1;
    while (n != 0)
    {
        uj_n = uj_n + (n % 10) * hatvany;
        hatvany = hatvany * 2;
        n = n / 10;
    }
    return uj_n;
}

int main()
{
    unsigned int n1;
    unsigned long long n2;

    cout << "n1=";
    cin >> n1;
    cout << "Forditott n1=" << fordit(n1) << endl;
    if (palindrom(n1))
        cout << "n1 palindrom szam" << endl;
    else
        cout << "n1 nem palindrom szam" << endl;
    cout << alakit_10_2(n1) << endl;

    cout << "n2=";
    cin >> n2;
    cout << "Forditott n2=" << fordit(n2) << endl;
    if (palindrom(n2))
        cout << "n2 palindrom szam" << endl;
    else
        cout << "n2 nem palindrom szam" << endl;
    cout << alakit_2_10(n2) << endl;

    palindromok(200);

    return 0;
}