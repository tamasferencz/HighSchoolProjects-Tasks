#include <iostream>

using namespace std;

int main(){

    int m=0,c , n;

    cout << "Add meg az n-et: ";
    cin >> n;

    do{
        c = n%10;
        n = n/10;

        if(c==0){
            c=2;
        }else{
            if(c % 2 ==0){
            c=0;
            }
        }
        
        m = m * 10 + c;
    }while(n!=0);

    cout << m;

    return 0;
}