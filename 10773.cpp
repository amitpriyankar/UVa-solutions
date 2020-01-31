#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int ct=1;
    while(T--)
    {
        double v,u,d;
        cin>>d>>v>>u;
        cout<<setprecision(3);
        cout<<fixed;
        if(u>v&&u!=0&&v!=0)
        {
            cout<<"Case "<<ct++<<": "<<abs((float)(d/u)-(float)d/sqrt(u*u-v*v))<<endl;
        }
        else cout<<"Case "<<ct++<<": can't determine"<<endl;
    }
}