//K. p. ,a. billentyuzetrol feltolt egy n elemu tombot es eldonti, hogy a vektor szimetrikus-e vagy sem.

#include <iostream>

using namespace std;

int main(){

    int n;
    bool szim = true;

    cout << "Add meg az n-et: ";
    cin >> n;

    int u = n-1;
    int v[n];


    cout << "Add meg a tomb elemeit: " << endl;
    for(int i = 0; i < n; i++){
        cout << "v[" << i << "]= ";
        cin >> v[i];  
    }

    cout << "A tomb: ";
    for(int i = 0; i < n; i++){
        cout << v[i]<< " ";
    }
    
    cout << endl;

    for(int e = 0; e < n; e++){
        if(v[e] != v[u]){
            szim = false;  
        }
        u--;
    }
    if(szim){
        cout << "Szimmetrikus!";
    }else{
        cout << "Nem szimmetrikus!";
    }
    return 0;
}