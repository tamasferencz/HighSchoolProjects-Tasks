#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[100], szo[50];
    int i = 0, z;

    cout << "s=";
    cin.getline(s, 100);

    while (i < strlen(s))
    {
        strcpy(szo, "");
        z = 0;

        while (s[i] != ' ' && s[i] != '\0')
        {
            if (z == 0)
            {
                szo[z] = toupper(s[i]);
            }
            else
            {
                szo[z] = tolower(s[i]);
            }
            //cout << "z[" << z << "]=" << s[i] << endl;
            z++;
            i++;
        }
        szo[z] = '\0';
        i++;
        cout << szo << " ";
    }

    return 0;
}
