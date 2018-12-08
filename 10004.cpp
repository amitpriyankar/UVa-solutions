#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(true)
    {
        cin>>n;
        if(n==0)break;
        else{
            int l;
            cin>>l;
            vector<int>adj[n];
            vector<int>color(n+1,-1);
            int p,q;
            for(int i=0; i<l; i++)
            {
                cin>>p>>q;
                adj[p].push_back(q);
                adj[q].push_back(p);
            }
            queue<int> qu;
            bool check =true;
            for(int i=0; i<n; i++)
            {
                if(color[i]==-1)
                {
                    qu.push(i);
                    color[i]=0;
                    while(!qu.empty())
                    {
                        int v=qu.front();
                        qu.pop();
                        for(int u: adj[v])
                        {
                          
                            if(color[u]==-1)
                            {
                                color[u]=color[v]^1;
                                qu.push(u);
                            }
                            else{
                                check&=(color[v]!=color[u]);
                                
                            }
                           
                            
                        }

                    }
                }
            }
            cout<<((check)?"BICOLORABLE.":"NOT BICOLORABLE.");
            cout<<endl;


        }
    }
    return 0;
}