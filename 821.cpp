#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    int count=1;
    while(true)
    {
        
        cin>>a>>b;
        if(a==0&&b==0)return 0;
        vector<int> adj[101];
        int temp=-1;
        int sum=0;
        set<int> st;
    while(true)
    {
        st.insert(a);
        st.insert(b);
        temp=max(temp,max(a,b));
        adj[a].push_back(b);
        cin>>a>>b;
        if(a==0&&b==0)break;
        adj[a].push_back(b);
    }

    for(int i=1; i<=temp; i++)
    {
        queue<int> q;
        vector<int> d(101,0);
        vector<bool> visited(101,false);
        q.push(i);
        visited[i]=true;
        while(!q.empty())
        {
            int v=q.front(); q.pop();
            for(int u:adj[v])
            {
                if(!visited[u])
                {
                    visited[u]=true;
                    d[u]=d[v]+1;
                    q.push(u);
                }
            }
        }

        for(int i=1; i<=100; i++)sum+=d[i];
        // sum+=sum;
        // cout<<sum<<endl;
    }
   int tt=st.size();
   tt*=tt-1;
   //cout<<tt<<endl;
    float ans=(float)((float)sum/tt);
    cout<<setprecision(3);
    cout<<fixed;
    cout<<"Case "<<count++<<": average length between pages = "<<ans<<" clicks"<<endl;


    }
}