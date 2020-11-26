#include <iostream>

using namespace std;

int main()
{
    int n,a=0,b;
    cin>>n;
    int v[n],h[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]%2==0)
            {h[a]=v[i];
            a++;}
    }
    b=a;
    for(int i=0;i<n;i++)
            if(v[i]%2==1)
            {
                h[a]=v[i];
                a++;
            }
    for(int i=0;i<n;i++)
    {
        cout<<h[i]<< " ";
    }
    cout<<endl;
    for(int j=0;j<n;j++)
    {
        if(j<b-1)
        {
             for(int i=0;i<b-1;i++)
            {
                if(h[i]>h[i+1])
                {
                    int c;
                    c=h[i];
                    h[i]=h[i+1];
                    h[i+1]=c;
                }
            }
        }
        else
        {
             for(int i=n-1;i>b;i--)
             {
                 if(h[i]>h[i-1])
                 {
                     int s;
                     s=h[i];
                     h[i]=h[i-1];
                     h[i-1]=s;
                 }
             }
        }

    }
    for(int i=0;i<n;i++)
    {
        cout<<h[i]<< " ";
    }
    return 0;
}