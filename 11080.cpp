#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int inp=0; inp<n; inp++)
    {
        int v,e;
        cin>>v>>e;
        vector<int> adj[v];
        vector<int> color(v,-1);
        bool check=true;
        queue<int> que;
        int p,q;
        for(int i=0; i<e; i++)
        {
            cin>>p>>q;
            adj[p].push_back(q);
            adj[q].push_back(p);
        }
        for(int i=0; i<v; i++)
        {
            if(color[i]==-1)
            {
                que.push(i);
                color[i]=0;
                while(!que.empty())
                {
                    int v=que.front();
                    que.pop();
                    for(int u: adj[v])
                    {
                        if(color[u]==-1)
                        {
                            color[u]=color[v]^1;
                            que.push(u);
                        }
                        else check&=(color[v]!=color[u]);

                    }
                }
            }
        }
       int amit=0;
        if(check)
        {
            for(int i=0; i<color.size(); i++)if(color[i]==0)amit++;
            int sz=color.size()-amit;
            cout<<min(sz,amit);
            

        }
        else cout<<-1;
         cout<<endl;
       //for(int i=0; i<color.size(); i++)cout<<i<<" "<<color[i]<<endl;
       
       
    }
}