/*Beolvas 3 szamot: Irassatok ki a n szam kozul a legkissebet es a legnagyobbat. */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()  
{
    int legn, legk, szam, n;
    int v[n];

    cout << "n = ";
    cin >> n;

    cout << "Add meg az elso szamot: ";
    cin >> szam;

    legn = szam;
    legk = szam;

    srand(time(0));

    for(int i = 0; i < n; i++){
        v[i]= rand() % 101;
        cout << v[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < n; i++){
        if(legn < v[i]){
            legn = v[i];
        }
        if(legk > v[i]){
            legk = v[i];
        }
    }

    cout << "A legnagyobb: " << legn << endl;
    cout << "A legkisebb: " << legk << endl;

    return 0;
}