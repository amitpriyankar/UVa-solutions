#include <bits/stdc++.h>
using namespace std;
char  arr[1000009];
int binary_search(int l,int r,char val)
{
    int mid=l+(r-l)/2;
    if(r>=l)
    {
        if(l==r)return mid;
        else if(arr[mid]<val)return binary_search(mid+1,r,val);
        else return binary_search(l,mid,val);
    }
    else return -1;
}
int main()
{
    int aa,bb;
    int i=0;
    char c;
    while(true)
    {
        cin>>c;
        if(c=='\n')break;
        arr[i]=c;
        i++;
    }
    int tsize=i;
    int n;
    cin>>n;
    string s;
    bool check=true;
    while(n--)
    {
        cin>>s;
        int start=0;
        for(int i=0; i<s.size(); i++)
        {
            int temp;
                temp=binary_search(start,tsize-1,s[i]);
               if(arr[temp]!=s[i])
               {
                   check =false;
                   break;
               }
               else
               {
                   if(i==0)aa=temp;
                   else if(i==s.size())bb=temp;
                   start=++temp;
               }
            
           
        }
        if(check)cout<<"Matched "<<aa<<" "<<bb<<endl;
        else cout<<"Not matched"<<endl;
    }

}