#include <iostream>

using namespace std;

int main()
{
    int x = 2;
    int *p = new int;
    int *q = new int;

    *p = x;
    q = p;
    *p = *p + 1;
    *q = *q + 1;

    cout << "*p: " << *p << endl;
    cout << "p: " << p << endl;
    cout << "&p: " << &p << endl;

    cout << endl;

    cout << "*q: " << *q << endl;
    cout << "q: " << q << endl;
    cout << "&q: " << &q << endl;

    delete p;
    delete q;

        return 0;
}