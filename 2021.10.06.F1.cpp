/* Keszitsunk programot amely, dinamikus memoriafoglalast hasznalva beolvas ket valos
szamot,osszeadja oket egy valtozoba, majd az eredmenyt kiirja a kepernyore. */

#include <iostream>

using namespace std;

int main()
{
    float *x = new float;
    float *y = new float;
    float *z = new float;

    cout << "*x: ";
    cin >> *x;

    cout << "*y: ";
    cin >> *y;

    *z = *x + *y;

    cout << "Osszeguk: " << *z << endl;

    delete x;
    delete y;
    delete z;

    return 0;
}