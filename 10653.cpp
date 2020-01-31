#include<bits/stdc++.h>
using namespace std;
struct cord{
    int x;
    int y;
};
int main()
{
    while(true)
    {
        int r,c;
        cin>>r>>c;
        if(r==0&&c==0)return 0;
        bool ok[r][c];
        memset(ok,true,sizeof(ok));
        int k;
        cin>>k;
        while(k--)
        {
            int rval;
            cin>>rval;
            int ct,val;
            cin>>ct;
            while(ct--)
            {
                cin>>val;
                ok[rval][val]=false;
            }
        }
        int ix,iy,fx,fy;
        cin>>ix>>iy>>fx>>fy;
        queue<struct cord> q;
        struct cord init;
        init.x=ix,init.y=iy;
        int dis[r][c];
        memset(dis,0,sizeof(dis));
        q.push(init);
        while(!q.empty())
            {
                struct cord amit;
                amit=q.front();
                q.pop();
                int curx=amit.x;
                int cury=amit.y;
                for(int i=-1; i<=1; i++)
                {
                    for(int j=-1; j<=1; j++)
                {
                    if(abs(i)!=abs(j))
                    {
                    if(curx+i==r||(curx+i<0)||cury+j==c||(cury+j<0))continue;
                    if(ok[curx+i][cury+j])
                    {
                        ok[curx+i][cury+j]=false;
                    struct cord temp;
                    temp.x=curx+i;
                    temp.y=cury+j;
                    q.push(temp);
                    dis[curx+i][cury+j]=1+dis[curx][cury];
                    if(curx+i==fx&&cury+j==fy)
                    {
                        cout<<dis[curx+i][cury+j]<<endl;
                        break;
                    }
                    }
                    }
                }

                }
            }

    }
}