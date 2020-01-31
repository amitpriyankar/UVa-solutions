#include <bits/stdc++.h>
using namespace std;
#define amit "Case "<<ct++<<": "
int main()
{
    int ct=1;
    while(true)
    {
        int r,n;
        cin>>r>>n;
        if(r==0&&n==0)return 0;
       else  if(r-n>n*26)cout<<amit<<"impossible"<<endl;
        else cout<<amit<<((r>n)?ceil((float)(r-n)/n):0)<<endl;
        
    }
}