#include <iostream>

#ifndef DOBOZ_H
#define DOBOZ_H

using namespace std;

class Doboz
{
private:
    float sz, h, m;

public:
    static int szamlalo;

    Doboz();
    Doboz(float sz, float h, float m);

    float terfogat();
    void adatok();
    void kibont();
    virtual void vkibont();
};

int Doboz::szamlalo=0;

Doboz::Doboz()
{
    this->sz = 0;
    this->h = 0;
    this->m = 0;
    szamlalo++;
}

Doboz::Doboz(float sz, float h, float m)
{
    this->sz = sz;
    this->h = h;
    this->m = m;
    szamlalo++;
}

float Doboz::terfogat()
{
    return sz * h * m;
}

void Doboz::adatok()
{
    cout << "A doboz meretei: ";
    cout << sz << "x" << h << "x" << m << endl;
}

void Doboz::kibont()
{
    cout << "A doboz ures!!!" << endl;
}

void Doboz::vkibont()
{
    cout << "A doboz ures!!!" << endl;
}
#endif