#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[20];
    int i, j, n;

    strcpy(s, "informatie");
    n = strlen(s) - 1;
    for (i = 0; i < n / 2; i++)
        if (strchr("aeiou", s[i]) != NULL && strchr("aeiou", s[n - i]) != NULL)
        {
            s[i] = s[i + 1];
            s[n - i] = s[n - i - 1];
        }

    cout << s << endl;

    return 0;
}
