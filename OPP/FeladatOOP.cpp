#include <iostream>
#include <ctime>
#include "Ido.h"

using namespace std;

int main()
{

    time_t now = time(0);

    tm *ltm = localtime(&now);

    cout << "Time: " << ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;

    Ido ti1(ltm->tm_hour, ltm->tm_min, ltm->tm_sec);

    cout << "-> " << ti1.masodperc() << "sec" << endl;

    cout << endl;
    Ido ti2(439, 14, 56);
    cout << "A megadott ido: ";
    ti2.kiir();
    cout << "-> ";
    ti2.napszam();

    cout << endl;

    ++ti2;
    cout << ti2;
    ti2++;
    cout << ti2;
    --ti2;
    cout << ti2;
    ti2--;
    cout << ti2;

    cout << endl;

    if (ti1 == ti2)
        cout << "ti1=ti2" << endl;
    if (ti1 != ti2)
        cout << "ti1!=ti2" << endl;
    if (ti1 > ti2)
        cout << "ti1>ti2" << endl;
    if (ti1 >= ti2)
        cout << "ti1>=ti2" << endl;
    if (ti1 < ti2)
        cout << "ti1<ti2" << endl;
    if (ti1 <= ti2)
        cout << "ti1<=ti2" << endl;

    ti1.digitalis();
    cout << endl;
    Ido ti3(2, 50, 30);
    ti3.digitalis();
    cout << endl;
}