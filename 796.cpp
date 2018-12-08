#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj;
vector<bool> visited;
vector<int> fup,tin;
int timer;
int count,n;
vector<pair<int,int>> ans;
void dfs(int v,int p=-1)
{
    visited[v]=true;
    fup[v]=tin[v]=timer++;
   
    for(int u: adj[v])
    {
        if(u==p)continue;
        else if(visited[u])
        {
            fup[v]=min(fup[v],tin[u]);

        }
        else{
            dfs(u,v);
            fup[v]=min(fup[v],fup[u]);
            if(fup[u]>tin[v])
            {
               
               ans.push_back(make_pair(min(u,v),max(u,v)));
            }

        }
      

    }

}

void finding_bridges()
{
    timer=0;
    visited.assign(n,false);
    ans.clear();
    tin.assign(n,-1);
    fup.assign(n,-1);
    for(int i=0; i<n; i++)
    {
        if(!visited[i])dfs(i);
    }
}

int main()
{
   
    while(cin>>n)
    {
      
        adj.resize(n+1);
       
    
    int e,aa,it,bb;
    string bichme;
   
    for(int i=0; i<n;i++)
    {
        cin>>aa;
       cin>>bichme;
        string no;
        no=bichme.substr(1,bichme.size()-2);
        it=stoi(no);
        for(int l=0; l<it; l++)
        {
            cin>>bb;
            adj[aa].push_back(bb);
            adj[bb].push_back(aa);
        }
    }
    finding_bridges();
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<" critical links"<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].first<<" - "<<ans[i].second<<endl;
    }
    cout<<endl;
    
    string havana;
    getline(cin,havana);
    adj.clear();
   
    }
    
}