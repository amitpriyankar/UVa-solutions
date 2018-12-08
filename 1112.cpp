#include<bits/stdc++.h>
using namespace std;
int INF=INT_MAX;
int main()
{
    int T;
    cin>>T;
    string s;
    while(T--)
    {
        getline(cin,s);
        int n,s,t;
        cin>>n>>s>>t;
        using PII=pair<int,int>;
        vector<PII>adj[n+1];
        int e;
        cin>>e;
        int aa,bb,w;
        while(e--)
        {
            cin>>aa>>bb>>w;
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
        int ans=0;
        for(int i=1; i<=n ;i++)if(d[i]<=t)ans++;
        cout<<ans<<endl;
        
        if(T!=0)cout<<endl;
    }
}