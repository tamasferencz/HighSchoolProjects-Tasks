#include <iostream>
#include <fstream>

#define MAX_N 100

using namespace std;

int cssz;            //csucsok szama
int b[MAX_N][MAX_N]; //bool matrix
int t[MAX_N];        // tomb, ami a csucsok bejarasat tarolja

void beolvas()
{
    ifstream be("bool.in.txt");
    bool iranyitott;
    be >> cssz >> iranyitott;

    for (int i = 0; i < cssz; i++)
    {
        for (int j = 0; j < cssz; j++)
        {
            be >> b[i][j];
            if (i == j) // hurokelek kikuszobolese
            {
                b[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < cssz; i++)
    {
        for (int j = 0; j < cssz; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    be.close();
}

void szelessegiBejaras(int icsp)
{
    int vsor[2 * MAX_N];
    int e, u;
    int csucs;

    for (int i = 0; i < icsp; i++)
    {
        t[i] = false;
    }

    t[icsp - 1] = true;
    cout << "(" << icsp << ", ";

    e = 1;
    u = 1;
    vsor[u] = icsp;

    while (e <= u)
    {
        csucs = vsor[e];
        e++;
        for (int j = 0; j < cssz; j++)
        {
            if (b[csucs - 1][j] == j && t[j] == false)
            {
                t[j] = true;
                cout << j + 1 << ", ";
                u++;
                vsor[u] = j + 1;
            }
        }
    }

    cout << "\b\b"
         << ")" << endl;
}

int main()
{
    int icsp;
    beolvas();
    cout << "Kiindulo csucs: ";
    cin >> icsp;
    szelessegiBejaras(icsp);
    return 0;
}