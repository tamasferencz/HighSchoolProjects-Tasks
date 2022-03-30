#include <iostream>
#include <fstream>
#include <iomanip>

#define MAX_N 100
#define NAN 1000

short ut[MAX_N][MAX_N];
bool cs[MAX_N][MAX_N][MAX_N];
short cssz;

using namespace std;

void Beolvas()
{
    ifstream be("sulymatrix.txt");

    be >> cssz;
    cout << "CSUCS SZOG: " << cssz << endl;

    for (int i = 0; i < cssz; i++)
        for (int j = 0; j < cssz; j++)
        {
            be >> ut[i][j];
            cout << "UT: " << ut[i][j] << endl;
            if (i != j && ut[i][j] == 0)
                ut[i][j] = NAN;
            if (ut[i][j] == -1)
                ut[i][j] = NAN;
            for (int k = 0; k < cssz; k++)
                if (i != j && ut[i][j] != NAN)
                {
                    cs[i][j][i] = true;
                    cs[i][j][j] = true;
                }
        }
}

void RoyFloyd()
{
    for (int k = 0; k < cssz; k++)
    {
        for (int i = 0; i < cssz; i++)
        {
            if (i != k)
            {
                for (int j = 0; j < cssz; j++)
                {
                    if (j != k)
                    {
                        if (ut[i][j] > ut[i][k] + ut[k][j])
                        {
                            ut[i][j] = ut[i][k] + ut[k][j];

                            for (int l = 0; l < cssz; l++)
                            {
                                cs[i][j][l] = cs[i][k][l] || cs[k][j][l];
                            }
                        }
                        else
                        {
                            if (ut[i][j] == ut[i][k] + ut[k][j])
                            {
                                for (int l = 0; l < cssz; l++)
                                {
                                    cs[i][j][l] = cs[i][k][l] || cs[k][j][l];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Kiir()
{
    cout << "Utmatrix: " << endl;
    for (int i = 0; i < cssz; i++)
    {
        for (int j = 0; j < cssz; j++)
            if (ut[i][j] != NAN)
                cout << setw(4) << ut[i][j];
            else
                cout << setw(4) << "oo";
        cout << endl;
    }
    for (int i = 0; i < cssz; i++)
    {
        for (int j = 0; j < cssz; j++)
        {
            cout << "(" << i + 1 << "->" << j + 1 << "): ";
            if (i == j)
                cout << "{" << i + 1 << "}" << endl;
            else if (ut[i][j] == NAN)
                cout << "nincs ut" << endl;
            else
            {
                cout << "{";
                for (int k = 0; k < cssz; k++)
                    if (cs[i][j][k])
                        cout << k + 1 << ",";
                cout << "\b"
                     << "} - " << ut[i][j] << " hosszu";
                cout << endl;
            }
        }
    }
}

int main()
{
    Beolvas();
    RoyFloyd();
    Kiir();
    return 0;
}