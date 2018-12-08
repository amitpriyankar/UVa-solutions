    #include <bits/stdc++.h>
    using namespace std;
    int coin[5]={1,5,10,25,50};
    long long  dp[30009][5];
    int main()
    {
        for(int i=0; i<30009; i++)
        {
            for(int j=0; j<5; j++ )
            {
                if(i==0)dp[i][j]=1;
                else if (j==0)
                {
                    if(i%coin[j]==0)dp[i][j]=1;
                    else dp[i][j]=0;

                }
                else if(coin[j]>i)
                {
                    dp[i][j]=dp[i][j-1];
                }
                else dp[i][j]=dp[i-coin[j]][j]+dp[i][j-1];
            }
        }
        
        
        int inp;

        while(cin>>inp)
        {
            if(dp[inp][4]==1)
            cout<<"There is only 1 way to produce "<<inp<<" cents change."<<endl;
        else cout<<"There are "<<dp[inp][4]<<" ways to produce "<<inp<<" cents change."<<endl;

        }
        
    }