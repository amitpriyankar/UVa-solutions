#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
int INF=INT_MAX;
int dijkstra(vector<PII> start[],int src,int dest)
{
     priority_queue<PII,vector<PII>,greater<PII>> Q;
        vector<int> p(27,-1);
        vector<int> d(27,INF);
        d[src]=0;
        Q.push({0,src});
        while(!Q.empty())
        {
            int v=Q.top().second;
            int d_v=Q.top().first;
            Q.top();
            if(d_v!=d[v])continue;
            for(auto u:start[v])  
            {
                int to=u.first;
                int len=u.second;
                if(d[v]+len<d[to])
                {
                    d[to]=d[v]+len;
                    p[to]=v;
                    Q.push({d[to],to});
                }
            }  

        }

        int ans=0;
        while(p[dest]!=-1)
        {
            int y=p[dest];
            ans=(ans|(1<<y));
            dest=y;
        }
        return ans;
}
int main()
{
    int n; 
    while(cin>>n)
    {
       
        if(n==0)return 0;
        vector<PII> start,end;
        char aa,bb,cc,dd;
        int ww;
        int e=n;
        while(n--)
        {
             
            cin>>aa>>bb>>cc>>dd>>ww;
            if(aa=='Y')
            {
                if(bb=='B')
                {
                
                   start[cc-'A'].push_back({dd-'A',ww});
                   start[dd-'A'].push_back({cc-'A',ww});
                }
                else start[cc-'A'].push_back({dd-'A',ww});
            }
            else{
                if(bb=='B')
                {
                    end[cc-'A'].push_back({dd-'A',ww});
                   end[dd-'A'].push_back({cc-'A',ww});

                }
                else end[cc-'A'].push_back({dd-'A',ww});
            }
        }
        map<cchar,int> mp;
        for(int i=0; i<26)
        cin>>aa>>bb;
        int src,dest;
        src=aa-'A';
        dest=bb-'A';
        int A,B;
        A=dijkstra(start,src,dest);
        B=dijkstra(end,src,dest);
        if((A&B)!=0)
        {
            int C=A&B;
            int temp=0;
            while(temp<32)
            {
                if((C&(1<<temp))!=0)cout<<
            }
        }
       

        
         
    }
}