#include <iostream>
#include "Doboz.h"
#include "Ajandek.h"

using namespace std;

int main()
{
    Doboz d1(2, 5, 8);
    d1.adatok();
    cout << "Terfogata: " << d1.terfogat() << endl;

    Doboz d2(7, 3, 2);
    d2.adatok();
    cout << "Terfogata: " << d2.terfogat() << endl;

    cout << "Dobozok szama: " << Doboz::szamlalo << endl;

    Ajandek a(5, 5, 6, 3.56);
    a.adatok();
    cout << "Terfogata: " << a.terfogat() << endl;
    a.kibont();
    a.vkibont();

    return 0;
}