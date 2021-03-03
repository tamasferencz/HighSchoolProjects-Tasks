#include <iostream>

using namespace std;
void sub(int n, int v[100], int a)
{
    int x = 0;
    for (int i = 0; i < n; i++)
        if (v[i] == a)
            x++;
    cout << "A megadott szam ennyiszer szerepel a vektorban: " << x << endl;
    if (x == 0)
    {
        cout << "da" << endl;
    }
    else
    {
        cout << "nu" << endl;
    }
}
int main()
{
    cout << "n=";
    int n;
    cin >> n;
    int v[n], i = 0;
    cout << "Add meg a szamokat:" << endl;
    do
    {
        cout << "v[" << (i + 1) << "]=";
        cin >> v[i];
        if (v[i] > 9999)
        {
            do
            {
                cout << "v[" << (i + 1) << "]=";
                cin >> v[i];
            } while (v[i] > 9999);
        }
        i++;
    } while (i < n);

    sub(n, v, 5);

    return 0;
}