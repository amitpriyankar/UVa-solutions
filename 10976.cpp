#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    while(cin>>k)
    {
        int count=0;
        int arr[k+5][2]={0};
        int ans=0;
        for(int i=k+1; i<=2*k; i++)
        {
           int j=(i*k)/(i-k);
           
                if((i*k)%(i-k)==0)
                {
                    arr[count][0]=i;
                    arr[count++][1]=j;
                    ans++;
                   
                }
            
        }
        cout<<ans<<endl;
         for(int i=0; i<ans; i++)
        {
           if(arr[i][0]!=0 && arr[i][1]!=0)
           {
               cout<<"1/"<<k<<" = 1/"<<max(arr[i][0],arr[i][1])<<" + 1/"<<min(arr[i][0],arr[i][1])<<endl;
           }
        }
        

        
    }
}