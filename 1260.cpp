#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int data[n];
        for(int i=0; i<n; i++)cin>>data[i];
        int ans[n+1]={0};
        int sum=0;
        int count=0;
        for(int i=0; i<n; i++)
        {
            
            for(int j=0; j<i; j++)
            {
                if(data[i]>=data[j])count++;
            }
        }
        cout<<count<<endl;
        
    }
}