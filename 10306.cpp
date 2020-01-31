#include <bits/stdc++.h>
using namespace std;
int trip[301][2];
void fun(int arr[],int size,int val)
{
    int dp[305]={0};
    for(int i=1; i<=val; i++)
    {
        int q=1000000;
        for(int j=0; j<size; j++)
        {
           if(arr[j]<=i)
           {
               q=min(q,1+dp[i-arr[j]]);
           }
        }
        dp[i]=q;
    }
    if(dp[val]==1000000)cout<<"not possible"<<endl;
    else cout<<dp[val]<<endl;
    return;
}


void pythagoreanTriplets(int limit)
{

	int a, b, c = 0;
	int m = 2;

	while (c < limit) {

		for (int n = 1; n < m; ++n) {

			a = m * m - n * n;
			b = 2 * m * n;
			c = m * m + n * n;

			if (c > limit)
				break;
            trip[c][0]=a;
            trip[c][1]=b;
		}
		m++;
	}
}

int main()
{
for(int i=0; i<301; i++)
{
    trip[i][0]=-1;
    trip[i][1]=-1;
}
    pythagoreanTriplets(301);
    int n;
    cin>>n;
    int m,s;
   
    while(n--)
    {
         cin>>m>>s;
         int a,b;
         int sum[m];   
         int t1=0,t2=0,sz=0;  
         bool check[305][305];
         for(int i=0; i<305; i++)
            for(int j=0; j<305; j++)check[i][j]=false;
        
         for(int i=0; i<m; i++)
         {
             cin>>a>>b;
             t1+=a; t2+=b;
             if(check[a][b]==0)
           {

           sum[sz++]=a+b;
           check[a][b]=1;
          
           }
           
         }
         
         
         
        if(t1!=0 &&  t2!=0 && (trip[s][0]>0 && trip[s][1]>0))
        fun(sum,sz,trip[s][0]+trip[s][1]);
        else 
         fun(sum,sz,s);

    }
}