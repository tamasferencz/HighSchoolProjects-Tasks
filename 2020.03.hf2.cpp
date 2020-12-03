#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[100], word[50];
    int i = 0, magan, z;
    char uj[255] = "";

    cout << "s=";
    cin.getline(s, 100);

    while (i < strlen(s))
    {
        strcpy(word, "");
        magan = 0;
        z = 0;

        while (s[i] != ' ' && s[i] != '\0')
        {
            word[z] = s[i];
            if (strchr("aeiou", s[i]) != 0)
            {
                magan++;
            }
            i++;
            z++;
        }
        word[z] = '\0';

        strcat(uj, word);
        if (magan == strlen(word))
        {
            strcat(uj, " ");
            strcat(uj, word);
        }
        strcat(uj, " ");

        i++;
    }

    cout << uj << endl;

    return 0;
}
