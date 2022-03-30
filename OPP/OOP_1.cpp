#include <iostream>
#include <string>

using namespace std;

class Auto
{
private:
    string marka, modell, szin;
    unsigned int ev, ar;

public:
    void Auto_set(string x, string y, string z)
    {
        marka = x;
        modell = y;
        szin = z;
    }

    void Auto_get()
    {
        cout << "Marka: " << marka << endl;
        cout << "Modell: " << modell << endl;
        cout << "Szin: " << szin << endl;
    }
};

int main()
{
    Auto kocsi;

    string x, y, z;

    cout << "Marka: ";
    cin >> x;
    cout << "Modell: ";
    cin >> y;
    cout << "Szind: ";
    cin >> z;

    kocsi.Auto_set(x, y, z);
    kocsi.Auto_get();

    return 0;
}