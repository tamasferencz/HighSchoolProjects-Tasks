#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[100], szo[50];
    int i = 0, j;

    cout << "s=";
    cin.getline(s, 100);

    while (i < strlen(s))
    {
        j = -1;
        strcpy(szo, "");
        while (s[i] != ' ' && s[i] != '\0')
        {
            j++;           //Elokeszitjuk a helyet a betunek
            szo[j] = s[i]; //Bemasoljuk a betut
            i++;           //Lepunk a karakterlancban
        }
        j++;
        szo[j] = '\0'; //Lezarjuk a szavat

        if (strlen(szo) % 2 == 0)
            cout << szo << endl;

        i++; //Szokoz atugrasa
    }

    return 0;
}
