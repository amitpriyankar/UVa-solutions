#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   long long arr[n];
   long long sum=0;
   long long x;
   for(int i=0; i<n; i++)
   {
       cin>>x;
       arr[i]=x;
       sum+=x;
   }
   long long start[n]={0};
   long long end[n]={0};
   start[0]=arr[0];
   end[n-1]=sum;
   for(int i=1; i<n; i++)
   {
       start[i]+=arr[i];
       end[n-1-i]=sum-start[i-1];
   }
   

}