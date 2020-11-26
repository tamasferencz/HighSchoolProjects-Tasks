#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[100], utb, x, y, t[10] = " succes";
    int i = 0, j = 0;

    cout << "s=";
    cin.getline(s, 100);

    while (i < strlen(s))
    {
        while (s[i] != ' ' && s[i] != '\0')
        {
            x = s[i];
            j++;
            i++;
        }

        if (x)
        {
            strcat(s, t);
        }

        cout << endl;
        cout << "X szo utolso betuje: " << x << endl; // az elso/kovetkezo szam utolso betuje
        cout << "Az X szo hossza: " << j << endl;     // az elso/kovetkezo szam hossza
        cout << endl;
        j = 0;
        utb = 0;

        i++;
    }

    cout << s << endl;

    return 0;
}
