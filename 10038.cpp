#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int arr[n];
        int ans[n]={0};
        int a;
        bool check=false;
       
        for(int i=0; i<n; i++)
        {
            cin>>a;
            arr[i]=a;
            if(i>0){
                ans[abs(arr[i]-arr[i-1])]=1;
            }
            

        }
        for(int i=1; i<n; i++)
        {
            if(ans[i]==0)check=true;
        }
        cout<<(check?"Not jolly":"Jolly")<<endl;
    
        
    }
}