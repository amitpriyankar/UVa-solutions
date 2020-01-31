#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    string t;
    cin>>s>>t;
    int k;
    cin>>k;
    bool arr[26]={0};
    for(int i=0; i<26; i++)arr[i]=t[i]-'0';
    int n=s.size();
    int out;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int ans=0;
            for(int k=i; k<=j; k++)
            {
                if(arr[s[k]-'0'==0])ans++;
                
            }
            if(ans<=k)out++;
        }
    }
    cout<<out;
}
