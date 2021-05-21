/* Keszitsunk rekurziv alprogramokat amely egy szamot 10-es szamrendszerbol 2-be es 2-bol
10-es be alakit.
*/
#include <iostream>

using namespace std;

unsigned short ketto(unsigned long szam)
{
    if (szam == 0)
    {
        return 0;
    }
    else
    {
        return szam % 2 + 10 * ketto(szam / 2);
    }
}
unsigned short tiz(unsigned long szam)
{
    if (szam == 0)
    {
        return 0;
    }
    else
    {
        return szam % 10 + 2 * tiz(szam / 10);
    }
}

int main()
{
    unsigned int n;
    unsigned long m;
    cout << "n= ";
    cin >> n;
    cout << ketto(n) << endl;
    cout << "m= ";
    cin >> m;
    cout << tiz(m) << endl;

    return 0;
}