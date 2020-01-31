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
         
         
            int main()
            {
                tani_nachi_ke

                // string s;
                int T;
                cin >> T;
                while(T--)
                {
                    string s;
                    cin >> s;
                    vector<int> pi = prefix_function(s);
                    int n = s.size();
                    int j;
                    for(int i = n-1; i >= 0; i--)
                    {
                        int k = i + 1 - pi[i];
                        if((i+1)%k == 0 && 2*k == i+1)
                        {
                            j = k;
                            break;
                        }
                    }
                    int i = n%j;
                    int k = 8;
                    while(k--)
                    {
                        cout << s[i];
                        // cout << i << endl;
                        i++;
                        if(i == j)
                            i = 0;
                    }
                    cout << "...\n";


                }

               




               return 0;
            }