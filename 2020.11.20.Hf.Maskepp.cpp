#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[100], szo[50];
    int i = 0, j, z;

    z = i;

    cout << "s=";
    cin.getline(s, 100);

    while (i < strlen(s))
    {
        z = 0;
        j = 0;
        strcpy(szo, "");
        while (s[z] != ' ' && s[z] != '\0')
        {

            if (z == 0)
            {
                szo[j] = toupper(s[i]);
            }
            else
            {
                szo[j] = tolower(s[i]);
            }
            j++;
            z++;
            i++;
        }
        j++;
        szo[j] = '\0';
        i++;
        cout << szo << " ";
    }

    return 0;
}
