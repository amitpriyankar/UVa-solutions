#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int i=0; i<T; i++)
    {
        int n;
        
        cin>>n;
        int  arr[n];
        long long sum=0;
        int ans=1;
        
        for(int l=0; l<n; l++)
        {
            cin>>arr[l];
            if(l>0)
            {
                if(arr[l]>=sum)
                {
                    ans++;
                    sum+=arr[l];
                }
            }
            else if(l==0)sum=arr[l];
           
        }
        cout<<ans<<endl;
        
    }
}