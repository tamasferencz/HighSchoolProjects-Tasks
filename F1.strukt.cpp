#include <iostream>
#include <cmath>

using namespace std;

struct point
{
    int x;
    int y;
};

int main()
{

    point a1, a2;

    cout << "A kordinata= ";
    cin >> a1.x;

    cout << "B kordinata= ";
    cin >> a1.y;

    cout << "C kordinata= ";
    cin >> a2.x;

    cout << "D kordinata= ";
    cin >> a2.y;

    cout << "Tavolsag= " << sqrt(pow(a2.x - a1.x, 2) + pow(a2.y - a1.y, 2)) << endl;

    return 0;
}