#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream be("illeszkedesiMatrix_in.txt");
    int n, m;
    bool iranyitott = false;
    int db_h = 0, db_t = 0;

    be >> n >> m;
    int im[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            be >> im[i][j];
            if (im[i][j] == -1)
                iranyitott = true;
        }

    be.close();
    //a)
    cout << "Az illeszkedesi matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << im[i][j] << " ";
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
            for (int j = 0; j < m; j++)
            {
                if (im[i][j] == 1)
                {
                    bool van = false;
                    for (int k = 0; k < n; k++)
                        if (im[k][j] == -1)
                            van = true;
                    if (van)
                        kifok++;
                    else
                    {
                        kifok++;
                        befok++;
                        db_h++;
                    }
                }

                if (im[i][j] == -1)
                    befok++;
            }
            cout << (i + 1) << ". csucs - kifok: "
                 << kifok << " befok: " << befok
                 << endl;
        }
    }
    else
    {
        int fokszam;
        for (int i = 0; i < n; i++)
        {
            fokszam = 0;
            for (int j = 0; j < m; j++)
                fokszam = fokszam + im[i][j];
            cout << (i + 1) << ". csucs fokszama: "
                 << fokszam << endl;
        }
    }
    //c)
    if (iranyitott)
        cout << db_h << " hurokel van a grafban" << endl;
    //d)
    if (iranyitott)
    {
        int egy, m_egy;
        for (int j = 0; j < m; j++)
        {
            egy = -1;
            m_egy = -1;
            for (int i = 0; i < n; i++)
            {
                if (im[i][j] == 1)
                    egy = i;
                if (im[i][j] == -1)
                    m_egy = i;
            }
            for (int k = j + 1; k < m; k++)
                if (k != j)
                    if (im[k][egy] == -1 && im[k][m_egy] == 1)
                        db_t++;
        }
        cout << db_t << " tobbszoros el van a grafban" << endl;
    }
    return 0;
}