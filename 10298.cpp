#include <bits/stdc++.h>
using namespace std;

vector <int> divisors(int x)  // finding the factors
{                              // time complexity O(sqrt(n))
    vector <int> v;
    stack <int> st;
    for(int i=1; i<=sqrt(x); i++)
    {
        if(i*i==x)v.push_back(i);
        else if(x%i==0)
        {
            v.push_back(i);
            st.push(x/i);
        }

    }
    while(!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }
    return v;
}


int main()
{
    
    string s;
    int n;
    vector<int> f;
    int p=31;
    long long m=1e9+9;

    vector <long long> po(10000007);
    po[0]=1;
    for(int i=0; i<10000003; i++)
        {
            po[i+1]=(po[i]*p)%m;
           
        }

   
   
    while(cin>>s)
    {
        int ans=0;
        if(s==".")break;
        n=s.size();

         vector <long long > hs(n+1,0);
          hs[0]=0;
        for(int i=0; i<n; i++)     // hashing of given input string
        {
            hs[i+1]=(hs[i]+(po[i]*(s[i]-'a'+1)))%m;   
           
        }

        f=divisors(n);
        ans=0;
        for(int i=0; i<f.size(); i++)
        {
            int sz=f[i];
            string str=s.substr(0,sz);  // finding substring of it's facotor size
            long long hp=0;
            for(int i=0; i<sz ;i++)
            {
                hp=(hp+(po[i]*(str[i]-'a'+1)))%m;
               
            }
            bool check=false;
            for(int i=sz; i<n-sz+1; i=sz+i)
                {
                    long long cur_s=(hs[i+sz]-hs[i]+m)%m;
                    if(cur_s!=(hp*po[i])%m)
                   {
                       check=true;
                       break;
                   }     
                }

            if(check==0)
                {
                    cout<<n/sz<<endl;
                    ans=1;
                    break;                   
                }


         }

    } 
}

