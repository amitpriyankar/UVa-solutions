            #include <bits/stdc++.h>
            using namespace std;
            #define tani_nachi_ke  ios_base::sync_with_stdio(false); cin.tie(NULL);
            #define M_PI 3.14159265358979323846
            #define data data_
            #define ff first
            #define ss second
            #define pb push_back
            #define ll long long
            #define ld long double

            int const N = 85;
            int pref[N][N];
            int dp[N][N];

            vector<int> prefix_function(string const &s)
            {
                int n = s.size();
                // cout << s << endl;
                vector<int> pi(n,0);
                for(int i = 1; i < n; i++)
                {
                    int j = pi[i-1];
                    while(j > 0 && s[i] != s[j])
                        j = pi[j-1];
                    if(s[i] == s[j])
                        j++;
                    pi[i] = j;
                }
                // cout << pi[n-1] << endl;
                return pi;
            }
            string s;
            int fun1(int i,int j)
            {
                int n = j - i + 1;
                int k = n - pref[i][j];

                if(n%k == 0)
                    return k;
                else
                    return n;
            }
            int fun(int i,int j)
            {
                // cout << i << " " << j << endl;
                if(i > j)
                    return 1000000;
                else if(i == j)
                    return 1;
                else if(dp[i][j] != -1)
                    return dp[i][j];
                else
                {
                    int ans = 100000;
                    int k = fun1(i,j);
                    if(k != (j - i + 1))
                    {
                        ans = min(ans,fun(i,i+k-1));
                    }
                    for(int l = i; l <= j; l++)
                    {
                        int k = fun1(i,l);
                        if(k!=j+1-i)ans = min(ans,fun(i,i+k-1) + fun(l+1,j));
                        k = fun1(l,j);
                        if(k!=j+1-i)ans = min(ans,fun(l,l+k-1) + fun(i,l-1));
                    }    
                    return dp[i][j] = ans;
                }
            }
            int main()
            {
                tani_nachi_ke

                // string s;
                while(cin >> s)
                {
                    if(s == "*")
                        break;
                    memset(pref,0,sizeof(pref));
                    memset(dp,-1,sizeof(dp));
                    int n = s.size();
                    for(int i = 0; i < n; i++)
                    {
                        string t = s.substr(i,n-i);
                        vector<int> bin = prefix_function(t);
                        for(int j = 0; j < bin.size(); j++)
                            pref[i][i+j] = bin[j];
                    }

                    cout << fun(0,n-1) << '\n';


                }


               




               return 0;
            }