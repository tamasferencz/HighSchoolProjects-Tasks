#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[100];
    char k1, k2;

    cout << "s=";
    cin.getline(s, 100);

    cout << "Adja meg a karaktert(k1): ";
    cin >> k1;
    cout << "Adj meg egy masik karaktert(k2): ";
    cin >> k2;

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == k1)
        {
            s[i] = k2;
        }
        else if (s[i] == k2)
        {
            s[i] = k1;
        }
    }

    cout << s << endl;

    return 0;
}