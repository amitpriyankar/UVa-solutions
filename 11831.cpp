#include <bits/stdc++.h>
using namespace std;
int main()
{
     int dir;
    while(true)
    {
        int n,m,t;
        int ans=0;
        cin>>n>>m>>t;
        if(n==0 && m==0 && t==0)break;
        char arr[n][m];
        int p,q;
       
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>arr[i][j];
                char c=arr[i][j];
                
                if(c=='N'|| c=='S' || c=='L' || c=='O')
                {
                    p=i;
                    q=j;
                    if(c=='N')dir=0;
                    if(c=='L')dir=1;
                    if(c=='S')dir=2;
                    if(c=='O')dir=3;
                }
            }
        }
        char temp[t];
      
        int check=0;
       
        for(int i=0; i<t; i++)
            cin>>temp[i];
        for(int i=0; i<t; i++){
            if(temp[i]=='D')
            {
               dir++;
               dir=dir%4;
            }
            if(temp[i]=='E')
            {
                dir--;
                if(dir<0)
                dir=(dir+4)%4;

            }
            if(temp[i]=='F')
            {
                if(p-1>=0 && arr[p-1][q]!='#'&& dir==0)
                {
                   if(arr[p-1][q]=='*')
                   {
                       ans++;
                       arr[p-1][q]='.';
                   }
                   p--;
                }
                else if(dir==1 && q+1<=(m-1) && arr[p][q+1]!='#')
                {
                    
                    q++;
                    if(arr[p][q]=='*')
                   {
                       ans++;
                       arr[p][q]='.';
                   }
                    
                }
                else if(dir==2 && p+1<=(n-1) && arr[p+1][q]!='#')
                {
                    
                    p++;
                    if(arr[p][q]=='*')
                   {
                       ans++;
                       arr[p][q]='.';
                   }
                }
                else if(dir==3 && q-1>=0 && arr[p][q-1]!='#')
                {
                    
                    q--;
                    if(arr[p][q]=='*')
                   {
                       ans++;
                       arr[p][q]='.';
                   }
                }
               
            }
           
            
        }
        

            cout<<ans<<endl;
    }
    return 0;
}