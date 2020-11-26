#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[100];
    char i1, i2;

    cout << "s=";
    cin.getline(s, 100);

    do
    {
        cout << "Az egyik index: ";
        cin >> i1;
    } while (i1 < 0 || i1 >= strlen(s) - 1);

    do
    {
        cout << "A masik index: ";
        cin >> i2;
    } while (i2 < 0 || i2 >= strlen(s) - 1);

    if (i1 > i2)
    {
        int s = i1;
        i1 = i2;
        i2 = s;
    }

    strcpy(s + i1, s + i2 + 1);

    cout << s << endl;

    return 0;
}