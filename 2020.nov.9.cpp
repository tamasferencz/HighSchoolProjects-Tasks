#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[200];

    cout << "s=";
    cin.getline(s, 200);

    s[0] = toupper(s[0]);
    for (int i = 1; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            s[i - 1] = toupper(s[i - 1]);
            s[i + 1] = toupper(s[i + 1]);
        }
        s[strlen()]
    }
    return 0;
}