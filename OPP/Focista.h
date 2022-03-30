#include <cstring>
#include <iostream>

#ifndef FOCISTA_H
#define FOCISTA_H

using namespace std;

class Focista
{
private:
    //Évre/Szezonra - fix adatok
    const float alapfizetes = 30000;     // euro
    const unsigned int edzeshatar = 700; // ora
    const float edzesi_oradij = 1.5;
    const unsigned int golhatar = 25;
    const float jatek_dij = 100;
    // Focista adatok
    char nev[50];
    unsigned short igazolas_szam;
    unsigned short edzes_ido;
    unsigned short meccs_szam;
    unsigned short gol_szam;

public:
    Focista();
    Focista(char n[], unsigned short isz);
    Focista(char n[], unsigned short isz,
            unsigned short ei, unsigned short msz,
            unsigned short gsz);
    void edz(unsigned short ido);
    void jatszik();
    void goltRug();
    float fizetes();
    void adatok();
    void setNev(char _nev[]) { strcpy(this->nev, _nev); }
    void setIgazolas_szam(unsigned short _igazolas_szam)
    {
        this->igazolas_szam = _igazolas_szam;
    }
    void setEdzes_ido(unsigned short _edzes_ido)
    {
        this->edzes_ido = _edzes_ido;
    }
    void setMeccs_szam(unsigned short _meccs_szam)
    {
        this->meccs_szam = _meccs_szam;
    }
    void setGol_szam(unsigned short _gol_szam)
    {
        this->gol_szam = _gol_szam;
    }
    char *getNev()
    {
        char *_nev = new char(50);
        strcpy(_nev, nev);
        return _nev;
    }
    unsigned short getIgazolas_szam() { return igazolas_szam; }
    unsigned short getEdzes_ido() { return edzes_ido; }
    unsigned short getMeccs_szam() { return meccs_szam; }
    unsigned short getGol_szam() { return gol_szam; }
};

Focista::Focista()
{
    strcpy(this->nev, "Jhon Doe");
    this->igazolas_szam = 0;
    this->edzes_ido = 0;
    this->meccs_szam = 0;
    this->gol_szam = 0;
}

Focista::Focista(char n[], unsigned short isz)
{
    strcpy(this->nev, n);
    this->igazolas_szam = isz;
    this->edzes_ido = 0;
    this->meccs_szam = 0;
    this->gol_szam = 0;
}

Focista::Focista(char n[], unsigned short isz,
                 unsigned short ei, unsigned short msz,
                 unsigned short gsz)
{
    strcpy(this->nev, n);
    this->igazolas_szam = isz;
    this->edzes_ido = ei;
    this->meccs_szam = msz;
    this->gol_szam = gsz;
}

void Focista::edz(unsigned short ido)
{
    this->edzes_ido += ido;
}

void Focista::jatszik()
{
    this->meccs_szam++;
}

void Focista::goltRug()
{
    this->gol_szam++;
}

float Focista::fizetes()
{
    float fizetes = alapfizetes;

    if (edzes_ido >= edzeshatar)
        fizetes += edzes_ido * edzesi_oradij;

    if (gol_szam >= golhatar)
        fizetes += meccs_szam * jatek_dij;

    return fizetes;
}

void Focista::adatok()
{
    cout << "+--------------------------------+" << endl;
    cout << "| A focista neve: " << nev << "|" << endl;
    cout << "| Igazolas szam: " << igazolas_szam << "            |" << endl;
    cout << "| " << edzes_ido << " orat edzett eddig           |" << endl;
    cout << "| " << meccs_szam << " meccset jatszott eddig      |" << endl;
    cout << "| " << gol_szam << " golja van eddig             |" << endl;
    cout << "+--------------------------------+" << endl;
}

#endif // FOCISTA_H