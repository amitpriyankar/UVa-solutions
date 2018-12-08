#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n;
   
    for(int i=0; i<n; i++)
    {
        int amp,frq;
     
        getline(cin,s);
           cin>>amp>>frq;
        for(int l=0; l<frq; l++)
        {

        
            for(int j=1; j<=amp; j++)
                {
                    for(int k=1; k<=j; k++)
                    {
                        cout<<j;
                    }
                    cout<<endl;
                   

                }
                

                 for(int j=amp; j>=1; j--)
                {
                    for(int k=1; k<=j; k++)
                    {
                        cout<<j;
                    }
                    cout<<endl;
                   

                }



                if(l!=frq-1 || i!=n-1)cout<<endl;
        }        
    }

}