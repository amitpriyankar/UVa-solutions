#include <bits/stdc++.h>
using namespace std;
int INF=INT_MAX;
int main()
{
   
    int T;
    cin>>T;
    while(T--)
    {
       // cout<<INF<<endl;
        int n,m;
        cin>>n>>m;
        int boba;
        int arr[n+10][m+10];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>boba;
                arr[i][j]=boba;
            }
        }
        
        using PII=pair<int,int>;
        vector<vector<PII>> adj;
        adj.resize(n*m+1,vector<PII>(0));
        
       
        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            for(int aa=-1; aa<=1; aa++)
            for(int bb=-1; bb<=1; bb++)
            if(abs(aa)!=abs(bb))
            {
                if(i+aa<0||i+aa>n-1||j+bb<0||j+bb>m-1)continue;
              //  cout<<i<<" "<<j<<" "<<aa<<" "<<bb<<endl;
                adj[i*m+j+1].push_back({(i+aa)*m+j+bb+1,arr[i+aa][j+bb]});
            }
            
            
        }
        

        int const N=n*m+9;
        vector<int> d(N,INF);
        d[1]=arr[0][0];
        priority_queue<PII,vector<PII>,greater<PII>> q;
        q.push(make_pair(arr[0][0],1));
        while(!q.empty())
        {
            int v=q.top().second;
            int d_v=q.top().first;
            q.pop();
            if(d[v]!=d_v)continue;

            for(auto u:adj[v])
            {
                int to=u.first;
                int len=u.second;
                if(d[v]+len<d[to])
                {
                    d[to]=d[v]+len;
                    q.push({d[to],to});
                }
            }
        }
        cout<<d[n*m]<<endl;
        

    }
}