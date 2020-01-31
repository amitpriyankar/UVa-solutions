#include <bits/stdc++.h>
using namespace std;
vector<int> adj[30];
vector<int > color;
vector <int> parent;
int cycle_end;
int cycle_start;
bool dfs(int i)
{
    color[i]=1;
    for(int u: adj[i])
    {
        if(color[u]==0)
        {
            parent[u]=i;
            if (dfs(u)) return true;
        }
        else if(color[u]==1)
        {
            cycle_end=i;
            cycle_start=u;
            return true;
        }
    }
    color[i]=2;
    return false;
}
int main()
{
    while(true)
    {
        int n,e;
        cin>>n>>e;
        if(n==0&&e==0)break;
        unordered_map<string,int> umap;
        string p,q;
        int count=0;
        for(int i=1; i<=e; i++)
        {
            cin>>p>>q;
            if(umap[p]!=0)
            {
                umap[p]=count++;
            }
            if(umap[q]!=0)
            {
                umap[q]=count++;
            }
            adj[umap[p]].push_back(umap[q]);
            
           

        }

    }
}