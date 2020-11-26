/*Rendezzuk egy vektor elemeit a kovetkezo keppen: A vektor elejere a parpos
elemeket novekvo sorrendbe,a vektor vegere a paratlan elemeket csokkeno sorrendbe.*/

#include <iostream>

using namespace std;

bool parossz(int szam){
    if(szam % 2 == 0){
        return true;
    }else {
        return false;
    }

}

int main()
{
    int szam, n, m, b, j=0, b=0;

    cout << "Add meg az n-t: ";
    cin >> n;

    cout << "Add meg a szamokat: " << endl;

    int v[n];
    int z[j];
    int x[b];

    for(int i = 0; i< n; i++){
        cin >> szam;
    }

    for(int i = 0; i < n; i++){
        if(parossz(v[i])){
            z[j]=v[i];
        }       
        j++;
        cout << z[j] << " ";
    }


    return 0;
}