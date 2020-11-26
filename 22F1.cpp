    /*Beolvas 3 szamot: Irassatok ki a 3 szam kozul a legkissebet es a legnagyobbat. */

#include <iostream>

using namespace std;

int main()
{
    float a, b, c, legn, legk;

    cout << "Add meg a harom szamot: " << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    if(a > b && a > c){
        legn = a;
    }
    if(b > a && b > c){
        legn = b;
    }
    if(c > a && c > b){
        legn = c;
    }


    if(a < b && a < c){
        legk = a;
    }
    if(b < a && b < c){
        legk = b;
    }
    if(c < a && c < b){
        legk = c;
    }

    cout << "A legnagyobb: " << legn << endl;
    cout << "A legkisebb: " << legk << endl;

    return 0;
}