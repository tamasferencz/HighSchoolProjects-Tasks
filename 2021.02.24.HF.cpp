#include <iostream>

using namespace std;

// #define b = 5;

void szamjegyek(unsigned int a)
{
    cout << "Szamjegyei a(z) " << a << " nak/nek ={ ";
    for (unsigned int i = 0; i <= a; i++)
    {
        cout << a % 10 << " ";
        a = a / 10;
    }
    cout << a << "}" << endl;
}

// void szamj_szama(unsigned int v[b])
// {

//     cout << "A szam szamjegyeinek szama: ";
//     for (unsigned int i = 0; i < b; i++)
//     {
//         for (unsigned int j = 1; j < b - 1)
//         {
//             unsigned int c = 0;
//             if (v[i] = v[j])
//             {
//                 c += 1;
//             }
//         }
//         cout << "v[" << i << "]= " << c << endl;
//     }
// }

void szamj_ossz(unsigned int a)
{
    cout << "Szamjegyeinek oszzege a(z) " << a << " nak/nek = ";
    unsigned int x = 1;
    for (unsigned int i = 0; i <= a; i++)
    {
        x += a % 10;
        a = a / 10;
    }
    cout << x << endl;
}

void szamj_atlag(unsigned int a)
{
    cout << "Szamjegyeinek atlaga a(z) " << a << " nak/nek = ";
    float x = 1;
    float z = 1;
    for (unsigned int i = 0; i <= a; i++)
    {
        x += a % 10;
        a = a / 10;
        z++;
    }
    cout << x / z << endl;
}

int main()
{

    cout << "a)" << endl;
    szamjegyek(1375912);
    // cout << "b)" << endl;
    // szamj_szama(123412);
    cout << endl;
    cout << "c)" << endl;
    szamj_ossz(12345);
    cout << endl;
    cout << "d)" << endl;
    szamj_atlag(123456789);

    return 0;
}