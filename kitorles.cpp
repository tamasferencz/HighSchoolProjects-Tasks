#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[200], pre[10];
    char u[200];
    int poz;

    cout << "s=";
    cin.getline(s, 200);
    cout << "prefix=";
    cin.getline(pre, 10);

    while (strstr(s, pre) != 0)
    {
        char *x = strstr(s, pre);
        poz = x - s;
        strncpy(s + poz, x + strlen(pre), strlen(s) - strlen(pre));
    }

    cout << s << endl;

    return 0;
}
