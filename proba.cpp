#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[100];
    int i = 0, db = 0;

    cout << "s=";
    cin.getline(s, 2);

    cout << isdigit(s) << endl;

    return 0;
}
