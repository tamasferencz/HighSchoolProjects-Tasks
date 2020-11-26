#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[100];
    int db = 0, i = 0;

    cout << "s=";
    cin.getline(s, 100);

    while (i < strlen(s))
    {
        if (strchr("0123456789", s[i]) != 0)
        {
            db++;
            while (s[i] != ' ' && s[i] != '\0')
            {
                if (s[i] == ',')
                    db--;
                i++;
            }
        }
        i++;
    }

    cout << db;

    return 0;
}
