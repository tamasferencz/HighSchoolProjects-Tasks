#include <iostream>

using namespace std;

int main()
{
    int n, x = 0, ossz = 0, atlag;
    cin >> n;
    while (n != 0)
    {
        ossz = ossz + n;
        x++;
        cin >> n;
    }
    atlag = ossz / x;

    cout << "Atlag= " << atlag << endl;
    return 0;
}