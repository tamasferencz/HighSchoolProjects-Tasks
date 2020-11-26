#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){

    int n, legn, legk, a;

    cout << "n= ";
    cin >> n;

    srand(time(NULL));

    int v[n];

    for(int i=0;i<n;i++){
        v[i]=rand() % 100;  
    }

    legn = v[0];
    legk = v[0];

    for(int i=1;i<n;i++){
        if(v[i] > legn){
            legn = v[i];
        }
        if(v[i] < legk){
            legk = v[i];
        }
        
    }

    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }

    cout << endl;

    cout << "Legnagyobb= " << legn << endl;
    cout << "Legkisebb= " << legk << endl;

    return 0;
}