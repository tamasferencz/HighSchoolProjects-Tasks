#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream be("szomszedsagiLista_in.txt");
    int n;
    bool iranyitott;
    int hurokel = 0, db_t = 0;

    be >> n >> iranyitott;

    int b[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            be >> b[i][j];
        }
    }

    be.close();

    //a)
    cout << "Szomszedsagi Lista: " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (b[i][j] != 0)
            {
                cout << b[i][j] << " ";
            }
        }
        cout << endl;
    }

    //b)
    if (iranyitott)
    {
        int befok, kifok;
        for (int i = 0; i < n; i++)
        {
            kifok = 0;
            befok = 0;
            for (int j = 0; j < n - 1; j++)
            {
                if (b[i][j] != 0)
                {
                    kifok++;
                }
            }
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n - 1; k++)
                {
                    if (b[j][k] == i + 1)
                    {
                        befok++;
                    }
                }
            }
            cout << i + 1 << ". csucs kifoka " << kifok << " befoka: " << befok << endl;
        }
    }
    else
    {
        int fokszam = 0;
        for (int i = 0; i < n; i++)
        {
            fokszam = 0;
            for (int j = 0; j < n - 1; j++)
            {
                if (b[i][j] != 0)
                {
                    fokszam++;
                }
            }
            cout << "Az " << i + 1 << ". sor fokszama: " << fokszam << endl;
        }
    }

    //c)
    if (iranyitott)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (b[i][j] == i + 1)
                {
                    hurokel++;
                }
            }
        }
        cout << "Hurokelek szama: " << hurokel << endl;
    }
    else
    {
        cout << "Nincs hurokel!" << endl;
    }
    //d)
    if (iranyitott)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (b[i][j] != 0)
                {
                    for (int k = 0; k < n - 1; k++)
                    {
                        if (b[j - 1][k] == i + 1)
                        {
                            db_t++;
                        }
                    }
                }
            }
        }
        cout << db_t << " tobbszoros el van!" << endl;
    }

    return 0;
}