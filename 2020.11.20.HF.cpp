#include <iostream>
#include <cstring>

using namespace std;

char *ucfirst(char *szo)
{
    char *szo2 = new char[strlen(szo)];
    for (int i = 0; i < strlen(szo); i++)
    {
        szo2[i] = i == 0 ? toupper(szo[i]) : tolower(szo[i]);
    }
    return szo2;
}

int main()
{
    char s[102];
    char word[102];
    char *start;

    cout << "s=";
    cin.getline(s, 102);

    start = s;
    while (start != NULL)
    {
        strcpy(word, "");
        // cout << "start=" << start << endl;
        char *end = strstr(start, " ");
        // cout << "end=" << (end == NULL ? "null" : end) << endl;
        if (end == NULL)
        {
            strncpy(word, start, strlen(start));
            word[strlen(start)] = '\0';
        }
        else
        {
            int c = end - start;
            // cout << "c=" << c << endl;
            strncpy(word, start, c);
            word[c] = '\0';
        }
        // cout << "word=" << word << endl;
        char *uc = ucfirst(word);
        // cout << "uc=" << uc << endl;
        strncpy(start, uc, strlen(uc));
        start = end == NULL ? NULL : end + 1;
    }
    cout << "s=[" << s << "]";
    return 0;
}
