#include <bits/stdc++.h>
using namespace std;
int const N=1e6+9;
bool prime[N];
void fun()
{
    memset(prime,true,sizeof(prime));
    prime[1]=false;
    prime[0]=false;
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
    while(true)
    {
        int n;
        cin>>n;
        if(n==0)return 0;
        bool ok=true;
        for(int i=2; i<=n/2; i++)
        {
            if(prime[i]&&prime[n-i])
            {
                cout<<n<<" = "<<i<<" + "<<n-i<<endl;
                ok=false;
                break;
            }
        }
        if(ok)
        cout<<"Goldbach's conjecture is wrong.\n";
    }
}