#include <iostream>

using namespace std;

int main()
{
    int x = 5;
    int y = -7;

    cout << "x: " << x << endl;
    cout << "&x: " << &x << endl;
    cout << "y: " << y << endl;
    cout << "&y: " << &y << endl;

    x = x + 10;
    y = x;

    cout << "x: " << x << endl;
    cout << "&x: " << &x << endl;
    cout << "y: " << y << endl;
    cout << "&y: " << &y << endl;
    return 0;
}