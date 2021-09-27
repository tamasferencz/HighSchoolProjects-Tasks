#include <iostream>
#include <cstring>

using namespace std;

enum Szin
{
    PIROS = 6,
    KEK = 3,
    SARGA = 7,
    ZOLD = 2,
    LILA = 13
};

char *getColor(int sz)
{
    switch (sz)
    {
    case 2:
        return "ZOLD";
        break;
    case 3:
        return "KEK";
        break;
    case 6:
        return "PIROS";
        break;
    case 7:
        return "SARGA";
        break;
    case 13:
        return "LILA";
        break;
    default:
        return "Nem szin!";
    }
}

int getState(char szin[])
{
    if (strcmp(szin, "ZOLD") == 0)
    {
        return 2;
    }
    if (strcmp(szin, "KEK") == 0)
    {
        return 3;
    }
    if (strcmp(szin, "PIROS") == 0)
    {
        return 6;
    }
    if (strcmp(szin, "SARGA") == 0)
    {
        return 7;
    }
    if (strcmp(szin, "LILA") == 0)
    {
        return 13;
    }
    return 0;
}

int main()
{
    int state;

    cout << "Adj meg egy szint: ";
    cin >> state;
    cout << getColor(state) << endl;

    char color[15];

    cout << "Adj meg egy szint: ";
    cin >> color;
    cout << getState(color);

    return 0;
}