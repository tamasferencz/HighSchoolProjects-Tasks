/* K. p. a. feltolt egy nxm-es matrixot 0-100 kozotti veletlenszeru termeszetes szamokkal
majd kiirja, hogy a) Hanyadik sorban van a legnagyobb elem. b) Hanyadik oszlopban van a leg-
kisebb elem. c) Hany olyan elem van a tombben, amelynek sori ndexe paros,de az elem paratlan
vagy az oszlop indxe paratlan, de az elem paros.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    int n, m, legn=0, legk=100, x=0, y=0, db=0;

    cout << "Add meg az n-et: ";
    cin >> n;
    cout << "Add meg az m-et: ";
    cin >> m;

    int v[n][m];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            v[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(3)<< v[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] > legn)
            {
                legn = v[i][j];
                y=i;
            }
        }
    }
    cout << "Legnagyobb a(z)" << legn  << ", ami a " << y << " sorban van!";
    cout << endl;

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i][j] < legk)
            {
                legk = v[i][j];
                x=j;
            }
        }
    }
    cout << "Legkisebb a(z) " << legk << ", ami a " << x << " oszlop!";
    cout << endl;

    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i%2==0 && v[i][j]%2!=0){
                db++;
            }
            if(j%2!=0 && v[i][j]%2==0){
                db++;
            }
        }
    }

    cout << db << " darab c) alpontbeli elem van!" << endl;

    return 0;
}