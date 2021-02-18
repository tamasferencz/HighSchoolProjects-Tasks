#include <iostream>
#include <fstream>

using namespace std;

struct auto
{
    char nev[50];
    int km;
};

int main()
{
    ifstream be("./autok.txt");
    auto car[50];
    int n = 0, u = 0;

    if (be.fail())
        cout << "Nem nyithato az filmek.txt!" << endl;
    else
    {
        while (!be.eof())
        {
            be.getline(car[n].nev, 30);
            be >> car[n].km;
            be.get();
            n++;
        }
        be.close();

        for (int i = 0; i < n; i++)
        {
            if (car[n].km < 20.000)
            {
                u++;
            }
        }
        cout << u << " autó futott 20 ezer km-nél kevesebbet." << endl;
    }
    return 0;
}