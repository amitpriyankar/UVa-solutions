    #include<bits/stdc++.h>
    using namespace std;
    vector<int> adj[101];
    vector <bool> visited;
    vector <int> ans;
    void dfs(int i)
    {
        visited[i]=true;
        for(int u:adj[i])
            {
            if(!visited[u]) dfs(u);
            }
            ans.push_back(i);
        
    }
    int main()
    {
        while(true)
       {

        int n,m;
        cin>>n>>m;
        if(n==0 && m==0)break;
        int p,q;
        for(int i=0; i<m; i++)
        {
        cin>>p>>q;
        adj[p].push_back(q);  
        }
      
        visited.assign(n+1,false);
        ans.clear();
        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }
        reverse(ans.begin(),ans.end());
        for(int i=0; i<ans.size(); i++)cout<<ans[i]<<" ";
        cout<<endl;

        for(int i=0; i<101; i++)adj[i].clear();

        
    }
    return 0;   
    }
