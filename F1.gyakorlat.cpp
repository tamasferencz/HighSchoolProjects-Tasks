#include <iostream>
#include <ctime>

using namespace std;

struct termek
{
    char nev[50], kategoria[50];
    char alapmertek[50];
    float ar, mennyiseg;
    bool raktar;
    struct
    {
        int ev, honap, nap;
    } szavatossag;
};

int main()
{
    int n;
    char katt[50];
    char str[50];

    cout << "Add meg a termekek szamat: ";
    cin >> n;

    termek thing[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Neve: ";
        cin.get();
        cin.getline(thing[i].nev, 50);
        cout << "Kategoriaja: ";
        cin.getline(thing[i].kategoria, 50);
        cout << "Ara: ";
        cin >> thing[i].ar;
        cout << "Alapmertekegysege: ";
        cin.get();
        cin.getline(thing[i].alapmertek, 50);
        cout << "Mennyisege: ";
        cin >> thing[i].mennyiseg;
        cout << "Szavatossaganak eve: ";
        cin >> thing[i].szavatossag.ev;
        cout << "Szavatossaganak honapja: ";
        cin >> thing[i].szavatossag.honap;
        cout << "Szavatossaganak napja: ";
        cin >> thing[i].szavatossag.nap;
        cout << "Raktaron (van/nincs): ";
        cin.get();
        cin.getline(str, 50);
        thing[i].raktar = (strcmp(str, "van") == 0);
        cout << endl;
    }

    cout << endl;
    cout << "a) Rendezett formaban kiirva: " << endl;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Neve: " << thing[i].nev << endl;
        cout << "Kategoriaja: " << thing[i].kategoria << endl;
        cout << "Ara: " << thing[i].ar << endl;
        cout << "Alapmerteke kg-ben: " << thing[i].alapmertek << endl;
        cout << "Mennyisege: " << thing[i].mennyiseg << endl;
        cout << "Szavatossaga: " << thing[i].szavatossag.ev << " " << thing[i].szavatossag.honap << " " << thing[i].szavatossag.nap << endl;
        cout << "Van-e raktaron: " << thing[i].raktar << endl;
        cout << endl;
    }

    cout << endl;
    cout << "b) Kiirja a temekeket: " << endl;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Termek neve: " << thing[i].nev << endl;
    }

    cout << endl;
    cout << "c) Kiirja a bekert kategoriahoz tartozo termeket: " << endl;
    cout << endl;

    cout << "Adj meg egy kategoriat: ";
    cin.get();
    cin.getline(katt, 50);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(thing[i].kategoria, katt) == 0)
        {
            cout << "A hozza tartozo termek: " << thing[i].nev << endl;
        }
    }

    cout << endl;
    cout << "d) Kiirja azokat a termekeket, amelyek nincsenek raktaron: " << endl;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (!thing[i].raktar)
        {
            cout << "A termek: " << thing[i].nev << endl;
        }
    }

    cout << endl;
    cout << "e) Rendezi a termékeket mennyiség szerint csökkenő sorrendbe";
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (thing[j].mennyiseg > thing[i].mennyiseg)
            {
                termek s = thing[j];
                thing[j] = thing[i];
                thing[i] = s;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "A termek: " << thing[i].nev << endl;
    }

    cout << endl;
    cout << "f) Kiírja a legfrissebb terméket" << endl;
    cout << endl;

    termek legn = thing[0];
    for (int i = 1; i < n; i++)
    {
        tm t1, t2;
        // year since 1900
        t1.tm_year = legn.szavatossag.ev - 1900;
        // month of year from 0 to 11
        t1.tm_mon = legn.szavatossag.honap - 1;
        t1.tm_mday = legn.szavatossag.nap;

        // year since 1900
        t2.tm_year = thing[i].szavatossag.ev - 1900;
        // month of year from 0 to 11
        t2.tm_mon = thing[i].szavatossag.honap - 1;
        t2.tm_mday = thing[i].szavatossag.nap;

        time_t mt1 = mktime(&t1);
        time_t mt2 = mktime(&t2);

        if (mt2 > mt1)
        {
            legn = thing[i];
        }
    }

    cout << "A legfrisseb termek: " << legn.nev << endl;

    return 0;
}
