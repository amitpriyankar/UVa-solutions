#include <bits/stdc++.h>
using namespace std;
int const N=2*1e5+9;
int parent[N],size[N];
int n,e;
pair<long long ,pair<int,int>> adj[N];
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
    int a=parent[x];
    int b=parent[y];
    if(a!=b)
    {
        if(size[a]<size[b])swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
}
long long kruskal()
{
    int x,y;
    long long cost,ans=0;
    for(int i=0; i<e; i++)
    {
        x=adj[i].second.first;
        y=adj[i].second.second;
        cost=adj[i].first;
        if(find_set(x)!=find_set(y))
        {
            ans+=cost;
            unite(x,y);
        }    
    }
    return ans;
}
int main()
{
    vector<int> vec;
    while(true)
    {
    
    cin>>n>>e;
    if(n==0&&e==0)
    {
        for(int i=0; i<vec.size(); i++)cout<<vec[i]<<endl;
        return 0;
    }
    for(int i=0; i<n; i++)make_set(i);
    long long sum=0;
    int aa,bb,ww;
    for(int i=0; i<e; i++)
    {
        cin>>aa>>bb>>ww;
        sum+=ww;
        adj[i]=make_pair(ww,make_pair(aa,bb));
    }
    sort(adj,adj+e);
    //cout<<sum-kruskal()<<endl;
    vec.push_back(sum-kruskal());
    }
}