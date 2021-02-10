#include <iostream>
#include <cmath>

using namespace std;

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct tanulo
{
    string nev;
    float jegy1, jegy2, jegy3, jegy4;
    int dolgozat;
    float media;
};

int main()
{
    int n, i, z;
    float atlag, y;
    cout << "Add meg az n-t: ";
    cin >> n;

    cin.get();

    tanulo tan[n];

    for (i = 0; i < n; i++)
    {

        cout << "A tanulo neve: ";
        getline(cin, tan[i].nev);
        cout << "A tanulo 1. jegye: ";
        cin >> tan[i].jegy1;
        cout << "A tanulo 2. jegye: ";
        cin >> tan[i].jegy2;
        cout << "A tanulo 3. jegye: ";
        cin >> tan[i].jegy3;
        cout << "A tanulo 4. jegye: ";
        cin >> tan[i].jegy4;
        cout << "A tanulo dolgozata: ";
        cin >> tan[i].dolgozat;
        cin.get();
        tan[i].media = ((((tan[i].jegy1 + tan[i].jegy2 + tan[i].jegy3 + tan[i].jegy4) / 4) * 3) + tan[i].dolgozat) / 4;
        cout << "A tanulo mediaja: " << tan[i].media << endl;
    }

    for (i = 0; i < n; i++)
    {
        if (tan[i].media < 5)
        {
            cout << "Ez a tanulo megbukott: " << tan[i].nev << endl;
        }
    }

    for (i = 0; i < n; i++)
    {
        z++;
        y += tan[i].media;
    }

    atlag = y / z;

    cout << "Osztaly atlag: " << atlag << endl;

    for (i = 0; i < n; i++)
    {
        if (tan[i].media > atlag)
        {
            cout << "Ennek a diaknak a mediaja jobb, mint az osztalyatlag: " << tan[i].nev << endl;
        }
    }

    return 0;
}