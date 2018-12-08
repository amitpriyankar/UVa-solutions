#include <bits/stdc++.h>
using namespace std;
int INF=INT_MAX;
int main()
{
    int T;
    cin>>T;
    int ct=0;
    while(T--)
    {
        int n,m,s,e;
        cin>>n>>m>>s>>e;
        using PII=pair<int,int>;
        vector<PII> adj[n+1];
        int aa,bb,w;
        for(int i=0; i<m ;i++)
        {
            cin>>aa>>bb>>w;
            adj[aa].push_back({bb,w});
            adj[bb].push_back({aa,w});
        }
        priority_queue<PII,vector<PII>,greater<PII>> q;
        vector<int> d(n+1,INF);
        d[s]=0;
        q.push({0,s});
        while(!q.empty())
        {
            int v=q.top().second;
            int d_v=q.top().first;
            q.pop();
            if(d_v!=d[v])continue;
            for(auto edge:adj[v])
            {
                int to=edge.first;
                int len=edge.second;
                if(d[v]+len<d[to])
                {
                    d[to]=d[v]+len;
                    q.push({d[to],to});
                }
            }
        }
        cout<<"Case #"<<++ct<<": ";
        if(d[e]==INF)cout<<"unreachable"<<endl;
        else cout<<d[e]<<endl;
    }
}