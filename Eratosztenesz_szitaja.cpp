#include <iostream>

using namespace std;
int main()
{
    int n;
	cout << "n: ";
    cin >> n; 

	int v[n + 1];

	for(int i = 1; i <= n; i++){
        v[i]=i;
    }

	for(int i = 2; i <= n/2; i++){
		if(v[i] != 0){
			for(int j = i+1; j < n; j++){
				if(v[j] % v[i]==0){
					v[j]=0;
				}
        	}

		}
        
    }

	cout << n <<"-ig a primek: ";

	for (int i = 2; i < n; ++i) {
		if (v[i]) {
			cout << v[i] << " ";
		}
	}
}