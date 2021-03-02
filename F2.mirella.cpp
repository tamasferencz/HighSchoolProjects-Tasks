#include <iostream>

using namespace std;

unsigned int nr(unsigned int a, unsigned int k)
{
    cout << "A(z) " << a << " szamba keressuk a(z) " << k << "-nak/nek az ismetlodeset ami nem mas mint: ";
    unsigned int db = 0;
    for (unsigned int i = 0; i <= a; i++)
    {
        if (a % 10 == k)
        {
            db++;
        }
        a = a / 10;
    }
    return db;
}

int main()
{
    cout << nr(1252455, 5) << endl;

    return 0;
}