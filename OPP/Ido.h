#include <iostream>
#include <cmath>

#ifndef IDO_H
#define IDO_H

#define LENGTH 30

using namespace std;

class Ido
{
private:
    int h, m, s;
    static char c0[3][4];
    static char c1[3][4];
    static char c2[3][4];
    static char c3[3][4];
    static char c4[3][4];
    static char c5[3][4];
    static char c6[3][4];
    static char c7[3][4];
    static char c8[3][4];
    static char c9[3][4];
    static char points[3][3];

    int getDigits(char dest[3][LENGTH], int digit, int k);
    void copyDigits(char dest[3][LENGTH], char src[3][4], int k);
    int copyPoints(char dest[3][LENGTH], int k);

public:
    Ido();
    Ido(int h, int m, int s);
    Ido(const Ido &i);

    int masodperc();
    void napszam();
    void digitalis();
    void kiir();

    int getH() { return h; };
    int getM() { return m; };
    int getS() { return s; };
    void setH(int h) { this->h = h; }
    void setM(int m) { this->m = m; }
    void setS(int s) { this->s = s; }

    Ido operator++(int); // h++
    Ido &operator++();   //++h
    Ido operator--(int); // h--
    Ido &operator--();   //--h

    bool operator==(Ido i);
    bool operator!=(Ido i);
    bool operator<(Ido i);
    bool operator<=(Ido i);
    bool operator>(Ido i);
    bool operator>=(Ido i);

    friend ostream &operator<<(ostream &os, const Ido &t);
    friend istream &operator>>(istream &is, Ido &t);
};

char Ido::c0[3][4] = {{' ', '_', '_', ' '},
                      {'|', ' ', ' ', '|'},
                      {'|', '_', '_', '|'}};

char Ido::c1[3][4] = {{' ', ' ', ' ', ' '},
                      {' ', ' ', '/', '|'},
                      {' ', ' ', ' ', '|'}};

char Ido::c2[3][4] = {{' ', '_', '_', ' '},
                      {' ', '_', '_', '|'},
                      {'|', '_', '_', ' '}};

char Ido::c3[3][4] = {{' ', '_', '_', ' '},
                      {' ', '_', '_', '|'},
                      {' ', '_', '_', '|'}};

char Ido::c4[3][4] = {{' ', ' ', ' ', ' '},
                      {' ', '|', '_', '|'},
                      {' ', ' ', ' ', '|'}};

char Ido::c5[3][4] = {{' ', '_', '_', ' '},
                      {'|', '_', '_', ' '},
                      {' ', '_', '_', '|'}};

char Ido::c6[3][4] = {{' ', ' ', ' ', ' '},
                      {'|', '_', ' ', ' '},
                      {'|', '_', '|', ' '}};

char Ido::c7[3][4] = {{' ', '_', '_', ' '},
                      {' ', ' ', ' ', '|'},
                      {' ', ' ', ' ', '|'}};

char Ido::c8[3][4] = {{' ', '_', '_', ' '},
                      {'|', '_', '_', '|'},
                      {'|', '_', '_', '|'}};

char Ido::c9[3][4] = {{' ', ' ', '_', ' '},
                      {' ', '|', '_', '|'},
                      {' ', ' ', ' ', '|'}};
char Ido::points[3][3] = {{' ', ' ', ' '},
                          {' ', '.', ' '},
                          {' ', '.', ' '}};
Ido::Ido()
{
    this->h = 0;
    this->m = 0;
    this->s = 0;
}

Ido::Ido(int h, int m, int s)
{
    this->h = h;
    this->m = m;
    this->s = s;
}

Ido::Ido(const Ido &i)
{
    this->h = i.h;
    this->m = i.m;
    this->s = i.s;
}
void Ido::kiir()
{
    cout << this->h << ":" << this->m << ":" << this->s << endl;
}

int Ido::masodperc()
{
    int sec;
    sec = (this->h * 3600) + (this->m * 60) + this->s;
    return sec;
}

void Ido::napszam()
{
    int nap;
    nap = this->h / 24;
    cout << nap << "nap, " << this->h % 24 << ":" << this->m << ":" << this->s << endl;
}

void Ido::copyDigits(char dest[3][LENGTH], char src[3][4], int k)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dest[i][j + k] = src[i][j];
        }
    }
}

int Ido::copyPoints(char dest[3][LENGTH], int k)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dest[i][j + k] = this->points[i][j];
        }
    }
    return k + 3;
}

int Ido::getDigits(char dest[3][LENGTH], int digit, int k)
{
    switch (digit)
    {
    case 1:
        this->copyDigits(dest, this->c1, k);
        k += 4;
        break;
    case 2:
        this->copyDigits(dest, this->c2, k);
        k += 4;
        break;
    case 3:
        this->copyDigits(dest, this->c3, k);
        k += 4;
        break;
    case 4:
        this->copyDigits(dest, this->c4, k);
        k += 4;
        break;
    case 5:
        this->copyDigits(dest, this->c5, k);
        k += 4;
        break;
    case 6:
        this->copyDigits(dest, this->c6, k);
        k += 4;
        break;
    case 7:
        this->copyDigits(dest, this->c7, k);
        k += 4;
        break;
    case 8:
        this->copyDigits(dest, this->c8, k);
        k += 4;
        break;
    case 9:
        this->copyDigits(dest, this->c9, k);
        k += 4;
        break;

    default:
        this->copyDigits(dest, this->c0, k);
        k += 4;
        break;
    }
    return k;
}

void Ido::digitalis()
{
    char cT[3][LENGTH];
    int k = 0;
    if (this->h <= 9)
    {
        k = this->getDigits(cT, 0, k);
        k = this->getDigits(cT, this->h, k);
    }
    else if (this->h <= 23)
    {
        k = this->getDigits(cT, this->h / 10, k);
        k = this->getDigits(cT, this->h % 10, k);
    }
    k = this->copyPoints(cT, k);

    if (this->m <= 9)
    {
        k = this->getDigits(cT, 0, k);
        k = this->getDigits(cT, this->m, k);
    }
    else if (this->m <= 59)
    {
        k = this->getDigits(cT, this->m / 10, k);
        k = this->getDigits(cT, this->m % 10, k);
    }
    k = this->copyPoints(cT, k);

    if (this->s <= 9)
    {
        k = this->getDigits(cT, 0, k);
        k = this->getDigits(cT, this->s, k);
    }
    else if (this->s <= 59)
    {
        k = this->getDigits(cT, this->s / 10, k);
        k = this->getDigits(cT, this->s % 10, k);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << cT[i][j];
        }
        cout << endl;
    }
}

Ido Ido::operator++(int)
{
    this->h = this->h + 1;
    return *this;
}

Ido &Ido::operator++()
{
    this->h = this->h + 1;
    return *this;
}

Ido Ido::operator--(int)
{
    this->h = this->h - 1;
    return *this;
}

Ido &Ido::operator--()
{
    this->h = this->h - 1;
    return *this;
}

bool Ido::operator==(Ido i)
{
    return (i.masodperc() == this->masodperc());
}

bool Ido::operator!=(Ido i)
{
    return (i.masodperc() != this->masodperc());
}

bool Ido::operator>=(Ido i)
{
    return (i.masodperc() >= this->masodperc());
}

bool Ido::operator<=(Ido i)
{
    return (i.masodperc() <= this->masodperc());
}

bool Ido::operator<(Ido i)
{
    return (i.masodperc() < this->masodperc());
}

bool Ido::operator>(Ido i)
{
    return (i.masodperc() > this->masodperc());
}

ostream &operator<<(ostream &os, const Ido &i)
{
    os << i.h << ":" << i.m << ":" << i.s << endl;

    return os;
}

istream &operator>>(istream &is, Ido &i)
{
    is >> i.h >> i.m >> i.s;
    return is;
}

#endif