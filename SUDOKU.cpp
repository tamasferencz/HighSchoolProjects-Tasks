#include <iostream>
#include <fstream>

using namespace std;

int s[9][9];
int c[9][9];

ofstream ki("megoldas.txt");

void Beolvas()
{

    ifstream be("sudoku.txt");

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            be >> s[i][j];
            c[i][j] = s[i][j];
        }
    }

    be.close();
}
void Inicializal(int k)
{
}

void beallit(int k)
{
}

bool Letezik(int k)
{
}

bool Jo(int k)
{
}

bool Megoldas(int k)
{
}

void Kiir()
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
}

void Kiir_allomany()
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            ki << s[i][j] << " ";
        }
        ki << endl;
    }
    ki << "-------------------";
}
/*
void Backtracking()
{

    int i = 0;
    int j = 0;

    Inicializal(i, j);
    while (i > -1 && j > -1)
    {
        beallit(i, j);
        if (Letezik(i, j))
        {
            if (Jo(i, j))
                if (Megoldas(i, j))
                {
                    Kiir();
                }
                else
                {
                    i++;
                    j++;
                    Inicializal(i, j);
                }
        }
        else
        {
            i--;
            j--;
        }
    }
}
*/
int main()
{
    Beolvas();
    // Backtracking();
    Kiir();
    Kiir_allomany();

    return 0;
}