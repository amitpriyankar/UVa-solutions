#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        long long arr[101]={0};
         arr[0]=n;
        int i=1;
        while(true)
        {
            cin>>n;
            arr[i++]=n;
            if(n==-999999)break;

        }
        int m=i;
        long long data[101][101];
        long long max=-9999999999999;
        for(int i=0; i<m; i++)data[i][i]=arr[i];
        for(int i=0; i<m-1; i++)
        {
            for(int j=i+1; j<m; j++)
            {
                if(i+j!=0)
                data[i][j]=arr[j]*data[i][j-1];
                if(data[i][j>max])max=data[i][j];
            }
        }
        cout<<max<<endl;

    }
}