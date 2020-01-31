#include <bits/stdc++.h>
using namespace std;
#define tani_nachi_ke ios_base::sync_with_stdio(false); cin.tie(NULL);
bool arr[21][21];
int n,m;
int ct;
void fun(int i,int j)
{
    if(i<0||i>=n||j<0||j>=m)return ;
    if(!arr[i][j%m])return;
    arr[i][j%m]=false;
    ct++;
    fun(i-1,j);
    fun(i+1,j);
    fun(i,((j-1+m)%m));
    fun(i,((j+1+m)%m));

}
int main()
{
    tani_nachi_ke
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(!cin.eof())
    {
        
        cin>>n;
        cin>>m;
        memset(arr,false,sizeof(arr));
        string s;
        char c;
        for(int i=0; i<n; i++)
        {
           cin>>s;
           transform(s.begin(),s.end(),s.begin(),::tolower);
           //cout<<s<<endl;
           for(int j=0; j<s.size(); j++)
           {
               if(i==0&&j==0)
               {
                   arr[i][j]=true;
                   c=s[j];
               }
               else if(s[j]==c)arr[i][j]=true;
               else arr[i][j]=false;
              
           }
        
          // cout<<s<<endl;
        }
        int startx,starty;
        cin>>startx;
        cin>>starty;
        if(!arr[startx][starty])
        {
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)arr[i][j]=(arr[i][j]^1);
        }
        fun(startx,starty);
        int mx=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(arr[i][j])
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty())
                    {
                        pair<int,int> cord=q.front;
                        q.pop();
                        int curx=cord.first;
                        int cury=cord.second;
                        for(int l=-1; l<=1; l++)
                        for(int r=-1; r<=1; r++)
                        {
                            if(abs(l+r)==1&&curx+l>=0&&curx+l<n)
                            {
                                if(arr[l+curx][(cury+m+r)%m])
                                {
                                    arr[l+curx][(cury+m+r)%m]=true;
                                    q.push({l+curx,(cury+r+m)%m});
                                }
                            }
                        }
                    }
                    ct=0;
                    fun(i,j);
                    mx=max(ct,mx);
                }
            }
        }
        cout<<mx<<endl;
        getline(cin,s);

       
    }
}