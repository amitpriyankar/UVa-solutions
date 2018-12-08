#include <bits/stdc++.h>
using namespace std;
int INF=1000000;
int main()
{
   // freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
    int T;
    cin>>T;
    int ct=1;
    while(T--)
    {
        int n;
        cin>>n;
        int start[n][n],end[n][n];
        for(int i=0; i<n;i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                {start[i][j]=INF;
                end[i][j]=INF;}
                else start[i][j]=0,end[i][j]=0;
            }
        }
        int r; cin>>r;
        int aa,bb;
        for(int i=0; i<r; i++)
        {
            cin>>aa>>bb;
            start[aa][bb]=1;
            start[bb][aa]=1;
            end[aa][bb]=1;
            end[bb][aa]=1;
        }
        int src,dest;
        cin>>src>>dest;
        for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            start[i][j]=min(start[i][j],start[i][k]+start[k][j]);
            end[i][j]=min(end[i][j],end[i][k]+end[k][j]);
        }
       int MAX=-1;
        for(int i=0; i<n; i++)
        {
            
            MAX=max(MAX,start[src][i]+end[i][dest]);
            
        }
        cout<<"Case "<<ct++<<": "<<MAX<<endl;
    }
}