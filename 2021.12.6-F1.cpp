#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream be("6.F1-in.txt");
    bool nSz = false;
    int m;
    be >> m;

    int el[m][2];

    for (int i = 0; i < m; i++)
    {
        be >> el[i][0] >> el[i][1];
    }
    be.close();

    cout << "Az ellista: " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << el[i][0] << " " << el[i][1] << endl;
    }
    cout << endl;

    //a)
    cout << "Nem szimpatikusak: " << endl;
    for (int i = 1; i < m; i++)
    {
        nSz = false;
        for (int j = 1; j < m; j++)
        {
            if (i != el[j][1])
            {
                nSz = true;
            }
        }
        if (nSz)
        {
            cout << el[i][0] << " ";
        }
    }
    cout << endl;

    return 0;
}