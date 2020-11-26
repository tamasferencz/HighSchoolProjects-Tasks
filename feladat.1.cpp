/* Keszits programot amely beker egy maximum 100 karakterbol allo karakterlancot
   melyben a szavak az angol ABC kis- es nagy betujebol allnak es egy-egy szokozzel
   vannak elvalasztva es kiirja, azt a karakterlancot melyet az eredeti karakterlancbol
   epitunk fel ugy, hogy, a paratlan hosszusagu szavakat megduplazzuk a paros hosszu-
   saguakat megduplazzuk(a megduplazott szavak koze szokozt teszunk). */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[100];
    char t[200];

    char szo[50];
    int i = 0, j;
    cout << "s=";
    cin.getline(s, 100);

    while (i < strlen(s))
    {
        j = -1;
        strcpy(szo, "");
        while (s[i] != ' ' && s[i] != '\0')
        {
            j++;
            szo[j] = s[i];
            i++;
        }

        j++;
        szo[j] = '\0';

        if (strlen(szo) % 2 == 1)
        {
            strcat(t, szo);
            strcat(t, ' ');
            strcat(t, szo);
            strcat(t, ' ');
        }
        else
        {
            strcat(t, szo);
            strcat(t, " ");
        }
        i++;
    }
    t[strlen(t) - 1] = '\0'; // Szokoz letorlese.

    cout << t;
    return 0;
}