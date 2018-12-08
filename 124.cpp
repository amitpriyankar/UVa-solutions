#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ans;
vector<int> adj[21];
vector<bool> visited;

 void dfs(int i);
 

int main()
{
   
    
   string s,t;
   while(getline(cin,s)&&getline(cin,t)) {
     //  for(int i=0; i<s.size(); i++)if(s[i]==' ')s.erase(i);
   
   // s.erase(remove(s.begin(),s.end(),' ')),s.end();
   //t.erase(remove(t.begin(),t.end(),' ')),t.end();

    cout<<s<<" "<<t<<endl;

  /*  unordered_map<char,int> umap;
    int n=s.size();
    for(int i=0; i<n; i++)umap[s[i]]=i;
    
       

       
       for(int i=0; i<t.size(); i=i+2)
       {
           adj[umap[t[i]]].push_back(umap[t[i+1]]);
       }
     for(int i=0; i<n; i++)
     {
         if(adj[umap[s[i]]].empty())cout<<i<<" ";
     }

      
        for(int j=0; j<n; j++)
        {
             visited.assign(n,false);
             ans.clear();


             for(int i=j; i<n+j; i++)
              {
        
                   if(!visited[i])
                   {
                        dfs(i);
                   }
                   i=(i+n)%n;
               }

               reverse(ans.begin(),ans.end());
               for(int i=0; i<n; i++)
               {
                   cout<<s[i];
               }
               cout<<endl;

        }
         cout<<endl;
         return 0;
       
        
       
*/
       
    }
    return 0;
}
void dfs(int i)
 {
     visited[i]=true;
     for(int l=0; l<adj[i].size(); l++)
     {
         int u=adj[i][l];
         if(!visited[u])dfs(u);
     }
     ans.push_back(i);
 }