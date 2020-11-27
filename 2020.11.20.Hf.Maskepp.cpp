#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[102], ut;
    int i = strlen(s) - 1, x;

    cout << "s:";
    cin.getline(s, 102);

    while (i != 0)
    {
        while (s[i] != ' ' && s[i] != '\0')
        {

            ut = s[i];
        }
        i--;
    }
    cout << "s= " << s << endl;

    return 0;
}
