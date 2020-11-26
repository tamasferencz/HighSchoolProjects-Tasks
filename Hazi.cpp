/* Készíts programot, amely bekéri egy n diákból álló osztály év végi médiáit,
majd kiírja az első három tanuló médiáját (feltüntetve, hogy melyik az I.,II.,III.), a bukók médiáját,
az osztály átlagmédiáját (a bukókat nem számoljuk bele) és az átlag fölötti médiákat.*/

#include <iostream>

using namespace std;

int main()
{
    int n, z = 0;
    float media, oatlag, x = 0, atlagf, y = 0, legn, s;

    cout << "Add meg a tanulok szamat: ";
    cin >> n;

    cout << "Add meg a tanulok mediait: " << endl;
    float jegyek[n];

    for (int i = 0; i < n; i++)
    {
        cin >> media;
        if (media <= 4)
        {
            cout << media << " (buko)" << endl;
        }
        if (media > y)
        {
            legn = media;
            y = media;
        }
        if (media > 4)
        {
            x = x + media;
            z++;
        }
        jegyek[i] = media;
    }
    oatlag = x / z;

    cout << endl;
    cout << oatlag << " (Atlag)" << endl;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (jegyek[i] > oatlag)
        {
            cout << jegyek[i] << " (Atlag folotti media) " << endl;
        }
    }

    cout << endl;

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(jegyek[i]< jegyek[j]){
                s = jegyek[i];
                jegyek[i] = jegyek[j];
                jegyek[j] = s;
            }
        }
    }

    cout << "Eltanulok: " << endl;
    cout << "I. - " << jegyek[0] << endl;
    cout << "II. - " << jegyek[1] << endl;
    cout << "III. - " << jegyek[2] << endl;

    return 0;
}
