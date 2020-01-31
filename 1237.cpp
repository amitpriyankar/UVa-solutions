#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int d;
        cin>>d;
        string s[d];
        int arr[d][2];
        int count=d,i=0;
        while(count--)
        {
            scanf("%s%d%d",s[i],&arr[i][0],&arr[i][1]);
            i++;
        }
        int q;cin>>q;
        int p,st;
        count=0;
        while(q--)
        {
            cin>>p;
            for(int i=0; i<d; i++)
            {
                if(p>=arr[i][0]&&p<=arr[i][1])
                {
                    count++;
                    st=i;
                }
            }
            if(count==0 || count>1)cout<<"UNDETERMINED"<<endl;
            else cout<<s[i]<<endl;

        }
        cout<<endl;

    }
}