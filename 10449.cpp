#include<bits/stdc++.h>
using namespace std;
int INF=INT_MAX;
struct edge{
    int x;
    int y;
    long long cost;
};
int main()
{
    int ct=0;
    int n;
    while(cin>>n)
    {
        int arr[n];
        for(int i=0; i<n ;i++)cin>>arr[i];
        vector<edge> adj;
        int r;
        cin>>r;
        int kk=r;
        int aa,bb;
        while(kk--)
        {
            cin>>aa>>bb;
            struct edge amit;
            amit.x=aa;
            amit.y=bb;
            int i=arr[aa-1];
            int j=arr[bb-1];
            amit.cost=(j-i)*(j-i)*(j-i);
            adj.push_back(amit);
        }
        int q;
        vector<long long>d(n+1,INF);
        d[1]=0;
        int check;
       
        for(int l=0; l<n-1; l++)
        {
            check=-1;
          
            for(int i=0; i<r; i++)
            {
                if(d[adj[i].x]<INF)
                if(d[adj[i].x]+adj[i].cost<d[adj[i].y])
                {
                   
                    d[adj[i].y]=max(-(long long)INF,d[adj[i].x]+adj[i].cost);
                    check=1;
                }
            }
        }
     for(int i=0; i<r; i++)
            {
                if(d[adj[i].x]<INF)
                if(d[adj[i].x]+adj[i].cost<d[adj[i].y])
                {
                   
                    d[adj[i].y]=-INF;
                    check=1;
                }
            }
        int qq,pp;
        cin>>qq;
        ct++;
        cout<<"Set #"<<ct<<endl;
        vector<int> ans;
        while(qq--)
        {
            cin>>pp;
        

        }

    }
}