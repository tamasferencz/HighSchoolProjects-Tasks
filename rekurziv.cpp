#include <iostream>
#include <fstream>

// A labirintus mérete
#define N 4

using namespace std;

ofstream ki("patkany.txt");

bool LabHasznalhato_e(int lab[N][N], int x, int y, int eredmeny[N][N]);

// Az eredményt kiíró alprogram
void kiiras(int eredmeny[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ki << " " << eredmeny[i][j];
        }
        ki << "\n";
    }
}
// Egy alprogram, ami nézi, hogy x és y valid index az N*N-es labirintushoz
bool adat_helyesseg(int lab[N][N], int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N && lab[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool megoldas(int lab[N][N])
{
    int eredmeny[N][N] = {{0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0}};

    if (LabHasznalhato_e(lab, 0, 0, eredmeny) == false)
    {
        cout << "Nincs megoldas!";
        return false;
    }

    kiiras(eredmeny);
    return true;
}
// A rekurziv alprogram, ami megoldja a labirintus probémát
bool LabHasznalhato_e(
    int lab[N][N], int x,
    int y, int eredmeny[N][N])
{
    if (x == N - 1 && y == N - 1 && lab[x][y] == 1)
    {
        eredmeny[x][y] = 1;
        return true;
    }
    if (adat_helyesseg(lab, x, y) == true)
    {
        if (eredmeny[x][y] == 1)
            return false;

        eredmeny[x][y] = 1;

        if (LabHasznalhato_e(lab, x + 1, y, eredmeny) == true)
        {
            return true;
        }

        if (LabHasznalhato_e(lab, x, y + 1, eredmeny) == true)
        {
            return true;
        }

        eredmeny[x][y] = 0;
        return false;
    }

    return false;

    ki.close();
}

int main()
{
    int lab[N][N] = {{1, 1, 1, 1},
                     {0, 0, 1, 0},
                     {1, 1, 1, 1},
                     {1, 0, 1, 1}};

    megoldas(lab);
    return 0;
}