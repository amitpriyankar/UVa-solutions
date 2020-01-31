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

        long long phi(long long n)
        {
            if(n == 1)
                return 0;
            long long res = n;
            for(long long i = 2; i * i <= n; i++)
            {
                if(n%i == 0)
                {
                    while(n%i == 0)
                        n/=i;
                    res -= res/i;
                }
            }
            if(n > 1)
                res -= res/n;
            return res;
        }
        int main()
        {
            tani_nachi_ke 

            long long n;
            while(cin >> n)
            {
                if(n == 0)
                    break;
                cout << phi(n) << '\n';
            }






           return 0;
        }