#include<bits/stdc++.h>
using namespace std;
struct edge{
    int x;
    int y;
    long long cost;
};
int INF=INT_MAX;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        vector<edge> adj;
        int aa,bb; long long w;
        for(int i=0; i<m; i++)
        {
            cin>>aa>>bb>>w;
            struct edge amit;
            amit.x=aa;
            amit.y=bb;
            amit.cost=w;
            adj.push_back(amit);
        }
     //   for(int i=0; i<adj.size(); i++)cout<<adj[i].cost<<endl;
        vector<long long> d(n+1,INF);
        d[0]=0;
        int tt=-1;
        for(int l=0; l<n; l++)
        {
            tt=-1;
            for(int i=0; i<m; i++)
            {
                if(d[adj[i].x]<INF)
                if(d[adj[i].x]+adj[i].cost<d[adj[i].y])
                {
                    tt=adj[i].x;
                    d[adj[i].y]=max((long long)-INF,d[adj[i].x]+adj[i].cost);
                   
                }
            }
        }
      //  cout<<tt<<endl;
        cout<<((tt!=-1)?"possible":"not possible")<<endl;
    }
}