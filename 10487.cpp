#include <bits/stdc++.h>
using namespace std;
int arr[1005];
int binary_ceil(int l ,int r ,int val)
{
    if(r>l)
    {
        int mid=l+(r-l+)/2;
        if (l==r)return mid;
        else if(arr[mid]<val)return binary_ceil(mid+1,r,val);
        else return binary_ceil(l,mid,val);
    }
    else return -1;
}
int main()
{
    int n;
    while(true)
    {
        cin>>n;
        if(n==0)return 0;
        for(int i=0; i<n; i++)cin>>arr[i];
        int m;
        cin>>m;
        int arr[m];
        for()
    }
}