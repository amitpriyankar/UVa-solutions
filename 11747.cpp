#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,pair<int,int>>
int const N=1009;
int parent[N],size[N];
void make_set(int v)
{
    parent[v]=v;
    size[v]=1;
}
int find_set(int v)
{
    if(parent[v]==v)return v;
    else return parent[v]=find_set(parent[v]);
}
void unite(int x,int y)
{
    int a=find_set(x);
    int b=find_set(y);
    if(a!=b)
    {
    if(size[a]<size[b])swap(a,b);
    parent[b]=a;
    size[a]+=size[b];
    }
}
int main()
{
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int n,e;
    while(true)
    {
        cin>>n>>e;
        if(n==0&&e==0)return 0;
        if(e==0)
        {
            cout<<"forest"<<endl;
            continue;
        }
        int aa,bb,ww;
        PII adj[e+1];
        for(int i=0; i<e; i++)
        {
            cin>>aa>>bb>>ww;
            adj[i]=make_pair(ww,make_pair(aa,bb));
        }
        for(int i=0; i<n; i++)make_set(i);
        sort(adj,adj+e);
        vector<int> ans;
        
        for(int i=0; i<e; i++)
        {
            int u=adj[i].second.first;
            int v=adj[i].second.second;
            if(find_set(u)!=find_set(v))
            {
                unite(u,v);
            }
            else
            {

             ans.push_back(adj[i].first);
            // cout<<adj[i].first<<endl;
            }
        }
        
        
        sort(ans.begin(),ans.end());
        //reverse(ans.begin(),ans.end());
        if(ans.size()==0)cout<<"forest"<<endl;
        else 
        {
            for(int i=0; i<ans.size(); i++)
            {
                cout<<ans[i];
                if(i!=ans.size()-1)cout<<" ";
            }
            cout<<endl;
        }
        

    }
}