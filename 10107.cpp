#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<long long int> v;
    long long x;
    while(cin>>x)
    {
        v.push_back(x);
        sort(v.begin(),v.end());
        cout<<((v.size()%2!=0)? v[v.size()/2]:(v[v.size()/2]+v[(v.size()+1)/2])/2);
    }
}