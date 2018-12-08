#include <bits/stdc++.h>
using namespace std;
int const N=INT_MAX;
bool prime[N];
void fun()
{
    memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for(int i=2; i*i<=N; i++)
    {
        if(prime[i])
        {
            for(int j=i*i; j<=N; j+=i)prime[j]=false;
        }
    }
}
int main()
{
    fun();
    int l,r;
    while(cin>>l)
    {
        cin>>r;
        int cl,ch,dl,dh;
        int maxx=-1,minn=N;
        int temp=-1;
        cout<<l<<r<<endl;
        for(int i=l; i<=r; i++)
        {
            
            if(prime[i])
            {
                temp=i;
                if(temp!=-1)
                {
                    if(i-temp<minn)
                    {
                        minn=i-temp;
                        cl=temp;
                        ch=i;
                    }
                    else if(i-temp>maxx)
                    {
                        maxx=i-temp;
                        dl=temp;
                        dh=i;
                    }
                }
            }
        }
        if(maxx==-1)cout<<"There are no adjacent primes.\n";
        else printf("%d,%d are closest, %d,%d are most distant.\n",cl,ch,dl,dh);
    }
}