#include "Tort.h"

int main()
{
    Tort t1(-2, 3);
    Tort t2(3, -2);
    Tort t3, t4;

    cout << t1 << t2;

    t3 = t1 + t2;
    cout << t3;
    t3 = t1 - t2;
    cout << t3;
    t3 = t1 * t2;
    cout << t3;
    t3 = t1 / t2;
    cout << t3;

    t1 += t2;
    cout << t1;
    t1 -= t2;
    cout << t1;
    t1 *= t2;
    cout << t1;
    t1 /= t2;
    cout << t1;

    t1++;
    cout << t1;
    t1--;
    cout << t1;
    ++t1;
    cout << t1;
    --t1;
    cout << t1;

    cout << "Adj meg egy tortet: ";
    cin >> t4;
    cout << t4;

    if (t1 == t2)
        cout << "t1=t2" << endl;
    if (t1 != t2)
        cout << "t1!=t2" << endl;
    if (t1 > t2)
        cout << "t1>t2" << endl;
    if (t1 >= t2)
        cout << "t1>=t2" << endl;
    if (t1 < t2)
        cout << "t1<t2" << endl;
    if (t1 <= t2)
        cout << "t1<=t2" << endl;
    return 0;
}