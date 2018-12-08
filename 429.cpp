#include <bits/stdc++.h>
using namespace std;
bool check(string s,string t)
{
    int ct=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]!=t[i])ct++;
    }
    if(ct==1)return true;
    else return false;
}
void solve()
{
    vector<int> adj[205];
    vector<bool> visited(205,false);
    unordered_map<string,int> mp;
    string arr[205];
    string s;
    int t=0;
    while(getline(cin,s))
    {
        if(s=="*")
        {
            string t1,t2;
            string st;
            while(getline(cin,st)&&st!="")
            {
                stringstream ss(st);
                ss>>t1>>t2;
                int aa=mp[t1];
                int bb=mp[t2];
                visited.assign(205,false);
                vector<int> d(205,0);
                queue<int> q;
                q.push(aa);
                visited[aa]=true;
                while(!q.empty())
                {
                    int v=q.front();
                    q.pop();
                    for(int u:adj[v])
                    {
                        if(!visited[u])
                        {
                            visited[u]=true;
                            q.push(u);
                            d[u]=d[v]+1;
                        }
                    }
                }
                cout<<t1<<" "<<t2<<" "<<d[bb]<<endl;
            }
          //  cout<<endl;
            return ;
            

        }
        else
        {
            arr[++t]=s;
             mp[s]=t;
            for(int i=1; i<t; i++)
            {
                if(arr[t].size()==arr[i].size()&&check(arr[i],arr[t]))
                {
                    adj[mp[arr[t]]].push_back(mp[arr[i]]);
                    adj[mp[arr[i]]].push_back(mp[arr[t]]);
                }
            }
        }
        
    }
}
int main()
{
    int T;
    cin>>T;
    string s;
        getline(cin,s);
    while(T--)
    {
        
        solve();
        if(T!=0)cout<<endl;
        
    }
}