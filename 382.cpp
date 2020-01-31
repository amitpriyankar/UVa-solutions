#include <bits/stdc++.h>
using namespace std;
int fun(int n)
{
    int sum=1;
    for(int i=2; i*i<=n ;i++)
    {
        if(n%i==0)
        {
            if(i*i==n)sum+=i;
            else 
            {
                sum+=i;
                sum+=n/i;
            }
        }
    }
    return sum;
}
int main()
{
    cout<<"PERFECTION OUTPUT\n";
    while(true)
    {
        int n;
        cin>>n;
        if(n==0)break;
        int a=fun(n);
        int boba=log10(n)+1;
        boba=5-boba;
        while(boba--)cout<<" ";
        cout<<n<<"  ";
        if(a==n&&n!=1)cout<<"PERFECT\n";
        else if(a<n||n==1)cout<<"DEFICIENT\n";
        else cout<<"ABUNDANT\n";
        
    }
    cout<<"END OF OUTPUT\n";
}