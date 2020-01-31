#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(true)
    {
        cin>>n;
        if(n==0)return 0;
        int globalmax,curr,curmax;
        for(int i=0; i<n; i++ )
        {
            cin>>curr;
            if(i==0){
                globalmax=curr;
                curmax=curr;
            }
            else{
                curmax=max(curr,curmax+curr);
                if(curmax>globalmax)globalmax=curmax;
            }
        }
        if(globalmax>0)cout<<"The maximum winning streak is "<<globalmax<<"."<<endl;
        else cout<<"Losing streak."<<endl;
    }
}