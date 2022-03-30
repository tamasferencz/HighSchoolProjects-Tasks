#include <iostream>
#include <cmath>

#ifndef TORT_H
#define TORT_H

using namespace std;

class Tort
{
private:
    int sz, n;

public:
    Tort();
    Tort(int sz, int n);
    Tort(const Tort &t); // másoló konstruktor
    void irreducibilis();

    Tort operator+(Tort t) const;
    Tort operator-(Tort t) const;
    Tort operator*(Tort t) const;
    Tort operator/(Tort t) const;

    Tort operator+=(const Tort &t);
    Tort operator-=(const Tort &t);
    Tort operator*=(const Tort &t);
    Tort operator/=(const Tort &t);

    Tort operator++(int); // t++
    Tort &operator++();   //++t
    Tort operator--(int); // t--
    Tort &operator--();   //--t

    bool operator==(Tort t);
    bool operator!=(Tort t);
    bool operator<(Tort t);
    bool operator<=(Tort t);
    bool operator>(Tort t);
    bool operator>=(Tort t);

    int getSz() { return sz; }
    int getN() { return n; }
    void setSz(int sz) { this->sz = sz; }
    void setN(int n) { this->n = n; }

    friend ostream &operator<<(ostream &os, const Tort &t);
    friend istream &operator>>(istream &is, Tort &t);
    friend bool operator==(const Tort &bt, const Tort &jt);
    friend bool operator!=(const Tort &bt, const Tort &jt);
    friend bool operator<(const Tort &bt, const Tort &jt);
    friend bool operator<=(const Tort &bt, const Tort &jt);
    friend bool operator>(const Tort &bt, const Tort &jt);
    friend bool operator>=(const Tort &bt, const Tort &jt);
};

Tort::Tort()
{
    this->sz = 0;
    this->n = 1;
}
Tort::Tort(int sz, int n)
{
    this->sz = sz;
    this->n = n;
}

Tort::Tort(const Tort &t)
{
    this->sz = t.sz;
    this->n = t.n;
}

void Tort::irreducibilis()
{
    if (n != 0)
    {
        int a = abs(this->sz);
        int b = abs(this->n);

        while (a != b)
            if (a > b)
                a = a - b;
            else
                b = b - a;

        this->sz = sz / a;
        this->n = n / b;
    }
    else
        cout << "0-val nem lehet osztani!" << endl;
}

Tort Tort::operator+(Tort t) const
{
    Tort tort(this->sz * t.n + t.sz * this->n, this->n * t.n);
    tort.irreducibilis();
    return tort;
}

Tort Tort::operator-(Tort t) const
{
    Tort tort(this->sz * t.n - t.sz * this->n, this->n * t.n);
    tort.irreducibilis();
    return tort;
}

Tort Tort::operator*(Tort t) const
{
    Tort tort(this->sz * t.sz, this->n * t.n);
    tort.irreducibilis();
    return tort;
}

Tort Tort::operator/(Tort t) const
{
    Tort tort(this->sz * t.n, this->n * t.sz);
    tort.irreducibilis();
    return tort;
}

Tort Tort::operator+=(const Tort &t)
{
    this->sz = this->sz * t.n + t.sz * this->n;
    this->n = this->n * t.n;
    irreducibilis();
    return *this;
}

Tort Tort::operator-=(const Tort &t)
{
    this->sz = this->sz * t.n - t.sz * this->n;
    this->n = this->n * t.n;
    irreducibilis();
    return *this;
}

Tort Tort::operator*=(const Tort &t)
{
    this->sz = this->sz * t.sz;
    this->n = this->n * t.n;
    irreducibilis();
    return *this;
}

Tort Tort::operator/=(const Tort &t)
{
    this->sz = this->sz * t.n;
    this->n = this->n * t.sz;
    irreducibilis();
    return *this;
}

Tort Tort::operator++(int)
{
    this->sz = this->sz + this->n;
    irreducibilis();
    return *this;
}

Tort &Tort::operator++()
{
    this->sz = this->sz + this->n;
    irreducibilis();
    return *this;
}

Tort Tort::operator--(int)
{
    this->sz = this->sz - this->n;
    irreducibilis();
    return *this;
}

Tort &Tort::operator--()
{
    this->sz = this->sz - this->n;
    irreducibilis();
    return *this;
}

bool Tort::operator==(Tort t)
{
    cout << "Nem barat" << endl;
    if (this->sz > t.sz)
        return ((float)this->sz / t.sz == (float)this->n / t.n);
    else
        return ((float)t.sz / this->sz == (float)t.n / this->n);
}

bool operator==(const Tort &bt, const Tort &jt)
{
    cout << "Barat" << endl;
    if (bt.sz > jt.sz)
        return ((float)bt.sz / jt.sz == (float)bt.n / jt.n);
    else
        return ((float)jt.sz / bt.sz == (float)jt.n / bt.n);
}

bool Tort::operator!=(Tort t)
{
    if (this->sz > t.sz)
        return ((float)this->sz / t.sz != (float)this->n / t.n);
    else
        return ((float)t.sz / this->sz != (float)t.n / this->n);
}

bool operator!=(const Tort &bt, const Tort &jt)
{
    if (bt.sz > jt.sz)
        return ((float)bt.sz / jt.sz != (float)bt.n / jt.n);
    else
        return ((float)jt.sz / bt.sz != (float)jt.n / bt.n);
}

bool Tort::operator<(Tort t)
{
    return ((float)this->sz / this->n < (float)t.sz / t.n);
}

bool operator<(const Tort &bt, const Tort &jt)
{
    return ((float)bt.sz / bt.n < (float)jt.sz / jt.n);
}

bool Tort::operator<=(Tort t)
{
    return ((float)this->sz / this->n <= (float)t.sz / t.n);
}

bool operator<=(const Tort &bt, const Tort &jt)
{
    return ((float)bt.sz / bt.n <= (float)jt.sz / jt.n);
}

bool Tort::operator>(Tort t)
{
    return ((float)this->sz / this->n > (float)t.sz / t.n);
}

bool operator>(const Tort &bt, const Tort &jt)
{
    return ((float)bt.sz / bt.n > (float)jt.sz / jt.n);
}

bool Tort::operator>=(Tort t)
{
    return ((float)this->sz / this->n >= (float)t.sz / t.n);
}

bool operator>=(const Tort &bt, const Tort &jt)
{
    return ((float)bt.sz / bt.n >= (float)jt.sz / jt.n);
}

ostream &operator<<(ostream &os, const Tort &t)
{
    if ((t.sz > 0 && t.n > 0) || (t.sz < 0 && t.n < 0))
        os << abs(t.sz) << "/" << abs(t.n) << endl;
    else
        os << "-" << abs(t.sz) << "/" << abs(t.n) << endl;
    return os;
}

istream &operator>>(istream &is, Tort &t)
{
    char c;
    is >> t.sz >> c >> t.n;
    return is;
}

#endif // TORT_H