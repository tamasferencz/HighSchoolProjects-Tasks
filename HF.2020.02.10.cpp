#include <iostream>
#include <fstream>

using namespace std;

struct film
{
    char cim[30], kategoria[30], rendezo[30];
    bool oscar;
    float ar;
    float ertekeles;
    struct
    {
        int ev, honap, nap;
    } datum;
    struct
    {
        int ora, perc;
    } ido;
};

void printMovie(film movie)
{
    cout << endl
         << "A film cime: " << movie.cim << endl;
    cout << "A rendezoje: " << movie.rendezo << endl;
    cout << "A megjelenesi datum: " << movie.datum.ev << " " << movie.datum.honap << " " << movie.datum.nap << endl;
    cout << "A kategoraija: " << movie.kategoria << endl;
    cout << "Idotartama: " << movie.ido.ora << " " << movie.ido.perc << endl;
    cout << "Ara: " << movie.ar << endl;
    cout << "IMDB ertekeles: " << movie.ertekeles << endl;
    cout << "Kapott-e Oscar dijat: " << movie.oscar << endl;
}

int main()
{
    ifstream be("./filmek.txt");
    int n = 0, u = 0, evSzam, x, osszi, maxh, minh;
    float atlag;
    float osszes = 0;
    char kAtegoria[50];
    film movie[50];
    char str[50];

    if (be.fail())
        cout << "Nem nyithato az filmek.txt!" << endl;
    else
    {
        while (!be.eof())
        {
            be.getline(movie[n].cim, 30);
            be.getline(movie[n].rendezo, 30);
            be >> movie[n].datum.ev;
            be.get();
            be >> movie[n].datum.honap;
            be.get();
            be >> movie[n].datum.nap;
            be.get();
            be.getline(movie[n].kategoria, 30);
            be >> movie[n].ido.ora;
            be.get();
            be >> movie[n].ido.perc;
            be.get();
            be >> movie[n].ar;
            be.get();
            be >> movie[n].ertekeles;
            be.get();
            be.getline(str, 30);
            movie[n].oscar = (strcmp(str, "igen") == 0);
            be.get();
            n++;
        }
        be.close();

        cout << endl
             << "a) Kiírja a filmeket rendezett formában " << endl;

        for (int i = 0; i < n; i++)
        {
            printMovie(movie[i]);
        }
        cout << endl
             << "b) Kiírja az Oscar-díjas filmeket" << endl;

        for (int i = 0; i < n; i++)
        {
            if (movie[i].oscar)
            {
                printMovie(movie[i]);
            }
        }
        cout << endl
             << "c) Bekér egy évszámot és kiírja az abban az évben megjelenő filmek címét és kategóriáját" << endl;

        cout << "Adj be egy evszamot: ";
        cin >> evSzam;

        for (int i = 0; i < n; i++)
        {
            if (movie[i].datum.ev == evSzam)
            {
                cout << "Cime: " << movie[i].cim << ", es kategoriajat: " << movie[i].kategoria << endl;
            }
        }

        cout << endl
             << "d) Bekér egy kategóriát és kiírja a hozzá tartozó filmek címét, rendezőjét és megjelenési dátumát" << endl;

        cout << "Add meg a kategoriat: ";
        cin >> kAtegoria;

        for (int i = 0; i < n; i++)
        {
            if (strcmp(movie[i].kategoria, kAtegoria) == 0)
            {
                cout << "Cime: " << movie[i].cim << ", rendezoje : " << movie[i].rendezo << ", datuma pedig: " << movie[i].datum.ev << " " << movie[i].datum.honap << " " << movie[i].datum.nap << endl;
            }
        }

        cout << endl
             << "e) Kiírja a leghosszabb és legrövidebb film/filmek címét és időtartamát" << endl;

        film legh;
        film legr;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                legh = movie[i];
                legr = movie[i];
            }
            else
            {
                if (((legh.ido.ora * 60) + legh.ido.perc) < ((movie[i].ido.ora * 60) + movie[i].ido.perc))
                {
                    legh = movie[i];
                }
                if (((legr.ido.ora * 60) + legr.ido.perc) > ((movie[i].ido.ora * 60) + movie[i].ido.perc))
                {
                    legr = movie[i];
                }
            }
        }

        cout << "A leghosszabb idotartamu film: " << legh.cim << ", idotartama: " << legh.ido.ora << " ora es " << legh.ido.perc << " perc." << endl;
        cout << "A legrovidebb idotartamu film: " << legr.cim << ", idotartama: " << legr.ido.ora << " ora es " << legr.ido.perc << " perc." << endl;

        cout << endl
             << "f) Kiírja az átlagértékelésnél nagyobb értékelésű filmek címét és értékelését" << endl;

        for (int i = 0; i < n; i++)
        {
            osszes += movie[i].ertekeles;
        }

        atlag = osszes / n;

        for (int i = 0; i < n; i++)
        {
            if (movie[i].ertekeles > atlag)
            {
                cout << "Az atlagnal nagyobb ertekelest ez a film kapta: " << movie[i].cim << ", ertekelese " << movie[i].ertekeles << endl;
            }
        }

        //g) Kiírja a filmeket ár szerint csökkenő sorrendben
        cout << endl
             << "g) Kiírja a filmeket ár szerint csökkenő sorrendben" << endl;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (movie[i].ar < movie[j].ar)
                {
                    film s = movie[i];
                    movie[i] = movie[j];
                    movie[j] = s;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            printMovie(movie[i]);
        }

        return 0;
    }
}