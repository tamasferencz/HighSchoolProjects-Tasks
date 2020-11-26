#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    int n,l;
    cout<<"n=";
    cin>>n;
    int a[n+1][n+1];
    srand(time(0));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
                a[i][j]=rand()%100;
        }
     for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)
            cout<<setw(3)<<a[i][j];
        cout<<endl;}
    l=a[1][1];
    cout<<endl;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            for (int ii=i+1;ii<=n;ii++)
                for (int jj=j+1;jj<=n;jj++)
                {
                    if (i==j && ii==jj && a[i][j]<a[ii][jj])
                    {
                        int s=a[i][j];
                        a[i][j]=a[ii][jj];
                        a[ii][jj]=s;
                    }
                }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)
            cout<<setw(3)<<a[i][j];
        cout<<endl;}
    return 0;
}