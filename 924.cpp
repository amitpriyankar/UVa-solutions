#include <bits/stdc++.h>
using namespace std;
int const N=2509;
int main()
{
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=0; i<n; i++)
    {
        int k;
        cin>>k;
        int a;
        while(k--)
        {
            cin>>a;
            adj[i].push_back(a);
            //adj[a].push_back(i);
        }
    }
    vector<bool> visited(n+1,false);
    vector<int> d(n+1,0);
    int T,p;
    cin>>T;
    while(T--)
    {
        cin>>p;
        visited.assign(n+1,false);
        d.assign(n+1,0);
        queue<int> q;
        q.push(p);
        visited[p]=true;
        int f[2509]={0};
        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            for(int u:adj[v])
            {
                if(!visited[u])
                {
                    visited[u]=true;
                    d[u]=d[v]+1;
                    f[d[u]]++;
                    q.push(u);
                }
            }
        }
        int max=-1,id;
        for(int i=0; i<=2505; i++)
        {
            if(f[i]>max)
            {
                max=f[i];
                id=i;
            }
        }
        if(max==0)cout<<0<<endl;
        else cout<<max<<" "<<id<<endl;
        

    }
}