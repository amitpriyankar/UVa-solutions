#include <bits/stdc++.h>
using namespace std;
#define tani_nachi_ke ios_base::sync_with_stdio(false); cin.tie(NULL);
int main()
{
    tani_nachi_ke 
    int l,U,r;
    int ct=1;
    while(true)
    {
        cin>>l>>U>>r;
        if(l==0&&U==0&&r==0)return 0;
        int arr[r];
        for(int i=0; i<r; i++)cin>>arr[i];
        queue<int> Q;
        vector<bool> visited(10000,false);
        visited[l]=true;
        Q.push(l);
        vector<int> d(10000,-1);
        d[l]=0;
        while(!Q.empty())
        {
            int v=Q.front();
            Q.pop();
            for(int i=0; i<r; i++)
            {
                int u=(arr[i]+v)%10000;
                if(!visited[u])
                {
                    Q.push(u);
                    visited[u]=true;
                    d[u]=d[v]+1;
                }
            }
        }
        cout<<"Case "<<ct++<<": ";
        if(d[U]==-1)cout<<"Permanently Locked\n";
        else cout<<d[U]<<endl;
    }
}