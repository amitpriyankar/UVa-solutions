#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,d,r;
    while(true)
    {
        cin>>n>>d>>r;
        if(n==0&&d==0&&r==0)return 0;
        int morn[n];
        int even[n];
        for(int i=0; i<n; i++)cin>>morn[i];
        for(int i=0; i<n; i++)cin>>even[i];
        sort(morn,morn+n);
        sort(even,even+n);
        int ans=0,sum=0;
        for(int i=0; i<n; i++)
        {
           
            sum=morn[i]+even[n-1-i]-d;
            if(sum>0)ans+=sum;
        }
        cout<<ans*r<<endl;
    }
}