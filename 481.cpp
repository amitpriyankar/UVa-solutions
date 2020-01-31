#include <bits/stdc++.h>
using namespace std;
vector<long long> a,b,p(1000000,-1);
long long len;
void find()
{
    b.push_back(0);
    long long u=0,v=0;
    if(a.empty())return;
    for(int i=1; i<a.size(); i++)
    {
        
        
        if(a[b.back()]<a[i])
        {
            p[i]=b.back();
            b.push_back(i);
            len++;
            continue;
        }
        u=0;
        v=b.size()-1;
        while(u<v)
        {
            long long mid=u+(v-u)/2;
            if(a[b[mid]]<a[i])u=mid+1;
            else v=mid;
        }
       
        if(a[i]<a[b[u]])
        {
            if(u>0)p[i]=b[u-1];
            b[u]=i;
        }
        
    }
    for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
  
}
int main()
{
   
    long long inp;
    while(cin>>inp)
    {
        a.push_back(inp);
    }
    p.resize(a.size());
   
    find();
    cout<<len+1<<endl<<"-"<<endl;
   
   for(int i=0; i<b.size(); i++)cout<<a[b[i]]<<endl;
    


    
    
}   