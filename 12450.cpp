#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int l=0; l<T; l++)
    {
        int n;
        cin>>n;
        char arr[n];
        int count=0;
       
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        int ans=0;
        for(int i=0; i<=n; i++)
        {
            if(arr[i]=='.')count++;
            if(count==2)
            {
                ans++;
                count=0;
                i++;
            }
        }
    }
}