#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[100];
    int i = 0, magan = 0, massal = 0, szo = 0;

    cout << "s=";
    cin.getline(s, 100);

    while (i < strlen(s))
    {
        massal = 0;
        magan = 0;

        while (s[i] != ' ' && s[i] != '\0')
        {
            if (strchr("aeiou", s[i]) != 0)
            {
                magan++;
            }
            else
            {
                massal++;
            }
            i++;
        }

        if (magan == massal)
        {
            szo++;
        }

        i++;
    }

    cout << "szo: " << szo << endl;

    return 0;
}
