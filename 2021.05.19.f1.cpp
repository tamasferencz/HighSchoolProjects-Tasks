/*Keszitsunk rekurziv alprogramot amely viszateriti a:
    a) a szam szamjegyeinke szamat.
    b) a szam szamjegyeinek osszeget.
    c) a forditott szamot

*/
#include <iostream>

using namespace std;

unsigned short szsz(unsigned long szam)
{
    if (szam == 0)
    {
        return 0;
    }
    else
    {
        return 1 + szsz(szam / 10);
    }
}

unsigned short szo(unsigned long szam)
{
    if (szam == 0)
    {
        return 0;
    }
    else
    {
        return szam % 10 + szo(szam / 10);
    }
}
/*
unsigned short fsz(unsigned long szam, unsigned long hatvany)
{
    if (szam == 0)
    {
        return 0;
    }
    else
    {
        return (szam % 10) * hatvany + fsz(szam / 10);
    }
}
*/
int main()
{
    cout << szsz(123456789) << endl;
    cout << szo(123456789) << endl;
    //cout << fsz(12345, h) << endl;

    return 0;
}