#include <bits/stdc++.h>
using namespace std;
#define amit "Case "<<ct++<<": "
int main()
{
    int T;
    cin>>T;
    int ct=1;
    while(T--)
    {
       int n;
       cin>>n;
       int p;
       for(int i=0; i<n; i++)
       {
           cin>>p;
           if(i==n/2)cout<<amit<<p<<endl;
       }
        
    }
}