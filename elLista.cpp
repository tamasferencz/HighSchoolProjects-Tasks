#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream be("elLista_in.txt");
    int m, n;
    be >> m >> n;
    bool iranyitott;
    be >> iranyitott;

    int hurokel = 0;

    int el[m][2];

    for (int i = 0; i < m; i++)
    {
        be >> el[i][0] >> el[i][1];
    }
    be.close();

    //a)
    cout << "Az ellista: " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << el[i][0] << " " << el[i][1] << endl;
    }
    cout << endl;

    //b)
    if (iranyitott)
    {
        int kifok, befok;
        for (int i = 1; i <= n; i++)
        {
            kifok = 0;
            befok = 0;
            for (int j = 0; j < m; j++)
            {
                if (el[j][0] == i)
                {
                    kifok++;
                }
                if (el[j][1] == i)
                {
                    befok++;
                }
            }
            cout << i << ". csucs kifoka: " << kifok << ", befoka " << befok << endl;
        }
    }
    else
    {
        int fokszam;
        for (int i = 1; i <= n; i++)
        {
            fokszam = 0;
            for (int j = 0; j < m; j++)
            {
                if (el[j][0] == i || el[j][1] == i)
                {
                    fokszam++;
                }
            }
            cout << i << ". fokszama: " << fokszam << endl;
        }
    }

    //c)
    if (iranyitott)
    {

        for (int i = 0; i < m; i++)
        {
            if (el[i][0] == el[i][1])
            {
                hurokel++;
            }
        }

        cout << "Hurokelek szama: " << hurokel << endl;
    }
    else
    {
        cout << "Nincs hurokel a grafban!" << endl;
    }

    //d)
    if (iranyitott)
    {
        int db_t = 0;
        for (int i = 0; i < m; i++)
        {

            for (int j = i + 1; j < m; j++)
            {
                if (el[i][0] == el[j][1] && el[i][1] == el[j][0])
                {
                    db_t++;
                }
            }
        }
        cout << db_t << " tobbszoros el van a grafban!" << endl;
    }
    return 0;
}