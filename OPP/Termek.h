#include <iostream>

#ifndef TERMEK_H
#define TERMEK_H

using namespace std;

class termek
{
private:
    char nev[20][20];
    int db[20];
    int kod[20];
    float e_ar[20];
    float b_ar[20];
    int z;
    float o_e_ar[20], o_b_ar[20], profit;

public:
    termek();
    void hozzaad_(void);
    void torol_(void);
    void elad_(void);
    void feltolt_(void);
    void kijelez_(void);
};

termek::termek()
{
    profit = 0;
    z = 0;
}

void termek ::hozzaad_(void)
{
    cout << "\nÍrja be a termék nevét: ";
    cin >> nev[z];
    cout << "Írja be a termék kódját: ";
    cin >> kod[z];
    cout << "Írja be a termék darabszámát: ";
    cin >> db[z];
    cout << "Írja be a termék eladási árát: ";
    cin >> e_ar[z];
    cout << "Írja be a termék beszerzési árát: ";
    cin >> b_ar[z];
    o_e_ar[z] = db[z] * e_ar[z];
    o_b_ar[z] = db[z] * b_ar[z];
    z++;
    system("clear");
}

void termek ::torol_(void)
{
    int i, j;
    bool talalat = false;
    cout << "\nÍrja be a termék kódját:";
    cin >> i;
    for (int j = 0; j < z; j++)
    {
        if (kod[j] == i)
        {
            db[j] = 0;
            o_e_ar[j] = 0;
            o_b_ar[j] = 0;
            cout << "\nA termék törölve lett!";
            profit -= db[j] * b_ar[j];
            talalat = true;

            break;
        }
    }
    if (!talalat)
    {
        cout << "Nincs ilyen kódú termék!" << endl;
    }

    system("clear");
}

void termek ::feltolt_(void)
{
    int i, j, s;
    float k;
    bool talalat = false;
    cout << "\nÍrja be a termék kódját:";
    cin >> i;

    for (int j = 0; j < z; j++)
    {
        if (kod[j] == i)
        {
            cout << endl;
            cout << "\nÍrja be mennyivel akarja feltölteni az árut:";
            cin >> k;
            db[j] += k;
            o_e_ar[j] = db[j] * e_ar[j];
            o_b_ar[j] = db[j] * b_ar[j];
            cout << "\nA termék fel lett töltve!" << endl;
            talalat = true;
            break;
        }
    }
    if (!talalat)
    {
        cout << "Nincs ilyen kódú termék!" << endl;
    }

    system("clear");
}

void termek ::elad_(void)
{
    char a;
    int i, j, k;
    bool talalat = false;

    cout << "\nÍrja be a termék kódját:";
    cin >> i;

    for (j = 0; j < z; j++)
    {
        if (kod[j] == i)
        {
            talalat = true;
            cout << "\nÍrja be, hogy mennyi terméket szeretne eladni:";
            cin >> k;
            if (k > db[j])
            {
                cout << "Nincs annyi termék!" << endl;
                break;
            }
            db[j] -= k;
            o_e_ar[j] = db[j] * e_ar[j];
            o_b_ar[j] = db[j] * b_ar[j];
            profit += k * (e_ar[j] - b_ar[j]);
            cout << "Eladva: " << k << ", profit: " << k * (e_ar[j] - b_ar[j]) << ", összprofit: " << profit << endl;
            break;
        }
    }
    if (!talalat)
    {
        cout << "Nincs ilyen kódú termék!" << endl;
    }
}

void termek ::kijelez_()
{
    int i, j = 1;

    for (i = 0; i < z; i++)
    {
        cout << endl;
        cout << j << ".A termék neve                           : " << nev[i];
        cout << "\n  A termék kódja                          : " << kod[i];
        cout << "\n  A termék mennyisége készleten           : " << db[i];
        cout << "\n  A termék eladási ára                    : " << e_ar[i] << " EUR/db";
        cout << "\n  A termék beszerzési ára                 : " << b_ar[i] << " EUR/db" << endl;
        cout << "\n  +---------------------------------------------------------+";
        cout << "\n  |    A készlet értéke eladási áron       : " << o_e_ar[i] << " EUR/db";
        cout << "\n  |    A készlet értéke beszerzési áron    : " << o_b_ar[i] << " EUR/db";
        cout << "\n  |    Profit                              : " << profit << " EUR";
        cout << "\n  +---------------------------------------------------------+";
        cout << endl;
        cout << endl;
        j++;
    }
}

#endif