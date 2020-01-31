#include<bits/stdc++.h>
using namespace std;
int INF=INT_MAX;
struct edge{
    int x;
    int y;
};
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==-1)return 0;
        vector<edge> adj;
        int ww,k;
        int arr[n+1];
        vector<int> graph[n+1];
        for(int i=0; i<n; i++)
        {
            cin>>ww>>k;
            int aa;
            arr[i+1]=ww;
            while(k--)
            {
                cin>>aa;
                struct edge amit;
                amit.x=i+1;
                amit.y=aa;
                //amit.cost=-ww;
                adj.push_back(amit);
                graph[i+1].push_back(aa);
            }
            
        }
        int e=adj.size();
     //   for(int i=0; i<e; i++)cout<<adj[i].x<<" "<<adj[i].y<<" "<<adj[i].cost<<endl;
        vector<int> d(n+1,-INF);
        d[1]=100;
        for(int l=0; l<n-1; l++)
        {
            for(int i=0; i<e; i++)
            {
                if(d[adj[i].x]>0)
                if(d[adj[i].x]+arr[adj[i].y]>d[adj[i].y])
                {
                    d[adj[i].y]=d[adj[i].x]+arr[adj[i].y];
                }
            }
        }
       
        // checking for cycles of possitive weight
        bool cycle=false;
            for(int i=0; i<e; i++)
            {
                if(d[adj[i].x]>0&&d[adj[i].x]+arr[adj[i].y]>d[adj[i].y])
                {
                    bool visited[n+1];
                    memset(visited,false,sizeof(visited));
                    //bool reach=false;
                    queue<int> Q;
                    Q.push(adj[i].x);
                    visited[adj[i].x]=true;
                    while(!Q.empty())
                    {
                        int v=Q.front();
                        Q.pop();
                        for(int u:graph[v])
                        {
                            if(!visited[u])
                            {
                                visited[u]=true;
                                Q.push(u);
                            }
                        }
                        
                        
                    }
                    
                    cycle|=visited[n];
                }
               
                
            }
            if(cycle||d[n]>0)cout<<"winnable\n";
            else cout<<"hopeless\n";
           // cout<<d[n]<<endl;
        
       
   
        

    }
}