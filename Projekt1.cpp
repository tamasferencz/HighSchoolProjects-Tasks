/*Egy osztalyba minden tanulo feladatot kap, hogy a ballagasa elott egy vegso osszegzest csinaljon, amelyben benne
kell legyen a tanulmanyi eredmenye(atlagot kap), a tanaroktol kapott ertekeles (diak viselkedese
szempontja szerint(JO, KOZEPES, ROSSZ)), a diakoktol egy ertekeles 1-10-es skalan(kozossegi szerepet mennyire toltotte be)
es egy magan ertekeles, ami azt tartalmazza, hogy, Hany szazalekosa fejlodese(egy ertek). A diak egy pontot fog kapni
1- a minimum, 100- a maximum.
*/

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#define MAX_DIAK_SZAM 4

struct ertekeles
{
    float atlag;
    unsigned short tanar;
    unsigned int diak;
    unsigned int fejlodes;
};

struct ertekelesSuly
{
    unsigned short atlag;
    unsigned short tanar;
    unsigned short diak;
    unsigned short fejlodes;
};

ertekeles minErtekeles()
{
    ertekeles ertekeles;
    ertekeles.atlag = 5;
    ertekeles.diak = 1;
    ertekeles.tanar = 1;
    ertekeles.fejlodes = 0;
    return ertekeles;
}
ertekeles maxErtekeles()
{
    ertekeles ertekeles;
    ertekeles.atlag = 10;
    ertekeles.diak = 10;
    ertekeles.tanar = 3;
    ertekeles.fejlodes = 100;
    return ertekeles;
}

ertekelesSuly zeroSuly()
{
    ertekelesSuly zero;
    zero.atlag = 0;
    zero.diak = 0;
    zero.fejlodes = 0;
    zero.tanar = 0;
    return zero;
}

bool zeroSuly(ertekelesSuly suly)
{
    return suly.atlag == 0 && suly.diak == 0 && suly.fejlodes == 0 && suly.tanar == 0;
}

struct diak
{
    unsigned short index;
    char nev[50];
    ertekeles ertekeles;
    float sulyozottAtlag;
};

float sulyozottAtlag(ertekeles ertekeles, ertekelesSuly suly)
{
    return (ertekeles.atlag * suly.atlag + ertekeles.diak * suly.diak + ertekeles.fejlodes * suly.fejlodes + suly.tanar) / (suly.atlag + suly.diak + suly.fejlodes + suly.tanar);
}

void diakKiirasa(diak diak)
{

    cout << diak.index << ". diak " << diak.nev << ", ertekelesei. \n";
    cout << "   Atlaga:                     " << diak.ertekeles.atlag << endl;
    cout << "   Tanari ertekelese(1-3):     " << diak.ertekeles.tanar << endl;
    cout << "   Diakok ertekelese(1-10):    " << diak.ertekeles.diak << endl;
    cout << "   Fejlodes(%):                " << diak.ertekeles.fejlodes << endl;
    if (diak.sulyozottAtlag > 0)
    {
        cout << "-------------------------------------------------------------------" << endl;
        cout << "   Sulyozott atlag(%):         " << diak.sulyozottAtlag << endl;
    }
    cout << "-------------------------------------------------------------------" << endl;
}

bool helyesBemenet(unsigned short diakokSzama, ertekelesSuly suly)
{
    return diakokSzama > 0 && !zeroSuly(suly);
}
void legjobbLeggyengebbDiak(diak *diakok, unsigned short diakokSzama, ertekelesSuly suly)
{
    if (!helyesBemenet(diakokSzama, suly))
    {
        cout << "Nincsenek diakok / Suly, elobb olvasd be oket!" << endl;
        return;
    }

    float mi = sulyozottAtlag(diakok[0].ertekeles, suly);
    float mx = mi;

    int n = 0;
    int m = 0;

    for (int i = 1; i < diakokSzama; i++)
    {
        float avrg = sulyozottAtlag(diakok[i].ertekeles, suly);
        if (avrg > mx)
        {
            mx = avrg;
            m = i;
        }
        if (avrg < mi)
        {
            mi = avrg;
            n = i;
        }
    }

    cout << "+--------------------------------------------+" << endl;
    cout << "| A leggyengebb diak " << diakok[n].nev << ", atlaga: " << mi << " :( " << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << "| A legjobb diak " << diakok[m].nev << ", atlaga: " << mx << " :) " << endl;
    cout << "+--------------------------------------------+" << endl;
}

void diakokSorrendberakas(diak *diakok, unsigned short diakokSzama, ertekelesSuly suly)
{
    if (!helyesBemenet(diakokSzama, suly))
    {
        cout << "Nincsenek diakok / Suly, elobb olvasd be oket!" << endl;
        return;
    }

    for (int i = 1; i < diakokSzama; i++)
    {
        for (int j = 0; j < (diakokSzama - 1); j++)
        {
            if (diakok[j].sulyozottAtlag > diakok[j + 1].sulyozottAtlag)
            {
                diak x = diakok[j];
                diakok[j] = diakok[j + 1];
                diakok[j + 1] = x;
            }
        }
    }
}

void diakokAtlagszamolasa(diak *diakok, unsigned short diakokSzama, ertekelesSuly suly)
{
    if (!helyesBemenet(diakokSzama, suly))
    {
        cout << "Nincsenek diakok / Suly, elobb olvasd be oket!" << endl;
        return;
    }

    cout << "+--------------------------------------------+" << endl;
    cout << "| Max. elerheto pontszam: "
         << sulyozottAtlag(maxErtekeles(), suly)
         << endl;

    cout << "+--------------------------------------------+" << endl;
    cout << "| Min. pontszam: "
         << sulyozottAtlag(minErtekeles(), suly)
         << endl;
    cout << "+--------------------------------------------+" << endl;

    for (int i = 0; i < diakokSzama; i++)
    {
        diakok[i].sulyozottAtlag = sulyozottAtlag(diakok[i].ertekeles, suly);
    }
    cout << "+--------------------------------------------+" << endl;
    cout << "| Atlagok kiszamolva " << endl;
    cout << "+--------------------------------------------+" << endl;
}

void diakokListazasa(diak *diakok, unsigned short diakokSzama)
{
    if (diakokSzama == 0)
    {
        cout << "Nincsenek diakok! Elobb olvasd be oket!\n";
    }
    else
    {
        for (int i = 0; i < diakokSzama; i++)
        {
            diakKiirasa(diakok[i]);
        }
    }
}

ertekelesSuly sulyBeolvasas()
{
    ertekelesSuly suly;

    cout << "Add meg az atlag sulyat: ";
    cin >> suly.atlag;
    cout << "Add meg a tanari ertekeles sulyat: ";
    cin >> suly.tanar;
    cout << "Add meg a diakok ertekeles sulyat: ";
    cin >> suly.diak;
    cout << "Add meg a fejlodes sulyat: ";
    cin >> suly.fejlodes;
    cout << endl;
    cin.get();
    return suly;
}

diak diakBelvasasa(fstream *be, unsigned short index)
{
    diak diak;

    diak.index = index + 1;
    diak.sulyozottAtlag = 0;

    be->getline(diak.nev, 50);
    *be >> diak.ertekeles.atlag;
    *be >> diak.ertekeles.tanar;
    *be >> diak.ertekeles.diak;
    *be >> diak.ertekeles.fejlodes;
    be->get();

    return diak;
}

unsigned short diakokBeolvasasa(diak *diakok)
{
    fstream be("diak.txt");
    unsigned short n = 0;
    while (!be.eof())
    {
        diakok[n] = diakBelvasasa(&be, n);
        n++;
        if (n >= MAX_DIAK_SZAM)
        {
            cout << ">>>> Vigyazat! Tobb diak a fajlban, mint a megengedett!" << endl;
            break;
        }
    }
    return n;
}

char menuKiirasa()
{
    cout << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << "|   DIAKOK ERTEKELESE MASKEPP (c).2021, FT   |" << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << "| Valasszon az alabbi menubol!               |" << endl;
    cout << "| 1. - Diakkok beolvasasa allomanybol        |" << endl;
    cout << "| 2. - A diakok listazasa                    |" << endl;
    cout << "| 3. - Sulyok bekerese                       |" << endl;
    cout << "| 4. - Sulyozott atlagok szamolasa           |" << endl;
    cout << "| 5. - Legjobb, leggyengebb diak             |" << endl;
    cout << "| 6. - Diakok sorrendbe rakasa               |" << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << "| x. - Kilepes                               |" << endl;
    cout << "+--------------------------------------------+" << endl;
    char x = cin.get();
    cin.get();
    return x;
}

int main()
{
    char menupont;
    diak diakok[MAX_DIAK_SZAM];
    ertekelesSuly suly = zeroSuly();
    unsigned short diakokSzama = 0;

    do
    {
        menupont = menuKiirasa();
        switch (menupont)
        {
        case '1':
            diakokSzama = diakokBeolvasasa(diakok);
            cout << "Beolvasva " << diakokSzama << " diak! " << endl;
            break;
        case '2':
            diakokListazasa(diakok, diakokSzama);
            break;
        case '3':
            suly = sulyBeolvasas();
            cout << "Suly beolvasva! " << endl;
            break;
        case '4':
            diakokAtlagszamolasa(diakok, diakokSzama, suly);
            break;
        case '5':
            legjobbLeggyengebbDiak(diakok, diakokSzama, suly);
            break;
        case '6':
            diakokSorrendberakas(diakok, diakokSzama, suly);
            break;
        }
    } while (menupont != 'x');
    return 0;
}