#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int k;
        cin>>k;
        int arr[300]={0};
        char c;
        int val,ans=0;
        while(k--)
        {
            cin>>c>>val;
            arr[c-'a']=val;
        }
        int M;
        cin>>M;
        string s;
        while(M--)
        {
            cin>>s;
            for(int i=0; i<s.size(); i++)
            {
                ans+=arr[s[i]-'a'];
            }
        }
        setprecision(2);
        double fin=(float)ans/100;
        cout<<fin<<endl;
    }
}