#include <bits/stdc++.h>
using namespace std;
int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        int i=0;
        char temp;
        vector<int> arr(24,0);
          do {
                 scanf("%d%c", &arr[i], &temp);
                  i++;
         } while(temp != '\n');
        int d,k;
        cin>>d>>k;
        long long check[1420]={0};
        for(int i=1; i<1420; i++)check[i]=i*(i+1)*d/2;
        long long sum=0;
        long long pp;
        for(int i=1; i<1420; i++)
        {
           
            if(k<=check[i]){
                pp=i;
                break;
            }
        }
       cout<<pp<<endl;
        long long  x=1;
        long long ai=0;
        for(int i=1; i<24; i++)
        {

            ai=ai+(arr[i]*x);
            x=x*pp;
          
        }
        cout<<ai<<endl;
        


    }

}