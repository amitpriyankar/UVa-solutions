#include <bits/stdc++.h>
using namespace std;
int n,m;
int knight[1000000];
bool check[1000000]={false};
int binary_ceil(int l, int r,int val)
{
    if(l>r)return -1;
    else{

    
    int mid=l+(r-l+1);
    if(l==r)return mid;
   else if(knight[mid]<val)l=mid+1;
    else r=mid;
    cout<<mid<<endl;
    }

}
int main()
{

    while(true)
    {
        cin>>n>>m;
        if(n==0 && m==0)return 0;
        int dragon[n];
        for(int i=0; i<n; i++)cin>>dragon[i];
        for(int i=0; i<m; i++)cin>>knight[i];
        sort(dragon,dragon+n);
        sort(knight,knight+m);
        if(n>m)
        {
            cout<<"Loowater is doomed!"<<endl;

        }
        else{

            int ans=0; 
            for(int i=0; i<n; i++)
            {
                int temp=binary_ceil(0,m-1,dragon[i]);
                if(knight[temp]>=dragon[i]&&!check[temp])
                {
                    ans+=knight[temp];
                    check[temp]=true;
                }
                else if(knight[temp]>=dragon[i]&& check[temp])
                {
                    if(temp==m-1)
                    {
                        ans=-1;
                        break;
                    }
                    ans+=knight[temp+1];
                    check[temp+1]=true;
               }
               else if(knight[temp]<dragon[i])
               {
                   ans=-1;
                   break;
               }
            
            }
            if(ans>0)cout<<ans<<endl;
            else cout<<"Loowater is doomed!"<<endl;
        }
    }
}