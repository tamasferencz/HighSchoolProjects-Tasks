#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[350];
    int i = 0, poz, hossz;

    cout << "s=";
    cin.getline(s, 350);

    while (i < strlen(s))
    {
        if (strchr("0123456789", s[i]) != 0 || (s[i] == '-' && strchr("0123456789", s[i + 1]) != 0))
        {
            poz = i;
            hossz = 1;
            while (s[i] != ' ' && s[i] != '\0')
            {
                i++;
                hossz++;
            }
            strcpy(s + poz + 1, s + poz + hossz - 1);
        }
        i++;
    }

    cout << endl
         << s << endl;

    return 0;
}
