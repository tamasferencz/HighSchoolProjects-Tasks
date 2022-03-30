#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream be("boolMatrix_in.txt");
    int n;
    bool iranyitott;
    int hurokel = 0, db_t = 0;

    be >> n >> iranyitott;

    int b[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            be >> b[i][j];
        }
    }

    be.close();

    //a)
    cout << "Boolmatrix: " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    //b)
    if (iranyitott)
    {
        int kifok, befok;
        for (int i = 0; i < n; i++)
        {
            kifok = 0;
            befok = 0;
            for (int j = 0; j < n; j++)
            {
                kifok = kifok + b[i][j];
                befok = befok + b[j][i];
            }
            cout << i << ". csucs kifoka " << kifok << ", mig a befoka " << befok << endl;
        }
    }
    else
    {
        int fokszam;
        for (int i = 0; i < n; i++)
        {
            fokszam = 0;
            for (int j = 0; j < n; j++)
            {
                fokszam = fokszam + b[i][j];
            }
            cout << i << ". csucs fokszama " << fokszam << endl;
        }
    }

    //c)
    if (iranyitott)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j && b[i][j] == 1)
                {
                    hurokel++;
                }
            }
        }
        cout << "Hurokelek szama: " << hurokel << endl;
    }

    //d)
    if (iranyitott)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (b[i][j] == b[j][i] && b[j][i] == 1 && i != j)
                {
                    db_t++;
                }
            }
        }
        cout << db_t << " tobbszoros el van a grafban!" << endl;
    }
    return 0;
}