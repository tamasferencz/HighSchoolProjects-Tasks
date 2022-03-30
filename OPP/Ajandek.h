#include <iostream>

#ifndef DOBOZ_H
#define DOBOZ_H

using namespace std;

class Ajandek : public Doboz
{
private:
    float suly;

public:
    Ajandek();
    Ajandek(float sz, float h, float m, float suly);

    void kibont();
    void vkibont();
};

Ajandek::Ajandek() : Doboz(float sz, float h, float m, float suly) : Doboz(sz, h, m)
{
    this->suly = 0;
}

void Ajandek::kibont()
{
    cout << "Meglepeteeees!!!" << endl;
}

void Ajandek::vkibont()
{
    cout << "Meglepeteeees!!!" << endl;
}
#endif