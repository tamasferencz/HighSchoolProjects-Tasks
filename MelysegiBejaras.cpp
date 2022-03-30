#include <iostream>
#include <fstream>

#define MAX_N 100

using namespace std;

int cssz;            //csucsok szama
int b[MAX_N][MAX_N]; //bool matrix
int t[MAX_N];        // tomb, ami a csucsok bejarasat tarolja

void beolvas()
{
    ifstream be("bool.txt");
    be >> cssz;
    for (int i = 0; i < cssz; i++)
        for (int j = 0; j < cssz; j++)
        {
            be >> b[i][j];
            if (i == j) // hurokelek kikuszobolese
            {
                b[i][j] = 0;
            }
        }
    be.close();
}

void melysegiBejaras(int icsp)
{
    int verem[MAX_N]; //verem
    int vs;           //veremsorolo
    int index;        //adott soron segit vegigmenni
    bool bejart;

    for (int i = 0; i < cssz; i++)
    {
        t[i] = false;
    }
    t[icsp - 1] = true;         //bejarjuk a csucsot
    cout << "(" << icsp << ","; //kiirjuk
    vs = 1;                     // veremsorolo a veremsorolo aljara
    verem[vs] = icsp;           //verembe helyezzuk a csucsot

    while (vs > 0)
    {
        index = 0;
        bejart = false;
        while (index < cssz && !bejart)
        {
            if (b[verem[vs] - 1][index] == 1 && t[index] == false)
            {
                t[index] = true;
                cout << (index + 1) << ",";
                vs++;
                verem[vs] = index + 1;
                bejart = true;
            }
            else
            {
                index++; //lepunk a kovetkezo csomopontra
            }
        }
        if (!bejart)
        {
            vs--;
        }
    }

    cout << "\b"
         << ")" << endl;
}

int main()
{
    int icsp;
    beolvas();
    cout << "Kiindulo csucs: ";
    cin >> icsp;
    melysegiBejaras(icsp);
    return 0;
}