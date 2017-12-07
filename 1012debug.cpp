#include<bits/stdc++.h>

using namespace std;

string graph[21];
int p,q;
int vis[21][21];
int cnt;
int r[]={-1,0,0,1};
int c[]={0,1,-1,0};

bool check(int posx,int posy)
{
    if(posx>=0&&posy>=0 && posx<q && posy<p && vis[posx][posy]==0 && graph[posx][posy]!='#') return true;
    else return false;
}

void dfs(int u,int v)
{
    vis[u][v]=1;

    for(int d=0;d<4;d++)
    {
        int posx=u+r[d];
        int posy=v+c[d];

        if(check(posx,posy))
        {
            dfs(posx,posy);
        }

    }

}

void akbar(int b,int a)
{
    int rootx,rooty;
    for(int x=0;x<a;x++)
    {
        cin>>graph[x];
        for(int y=0;y<graph[x].size();y++)
        {
            if(graph[x][y]=='@'){
                rootx=x;
                rooty=y;
            }
        }
    }
    dfs(rootx,rooty);

}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cnt=0;
        memset( vis, 0, sizeof vis);;
        cin>>p>>q;
        akbar(p,q);
        for( int j = 0; j < q; j++ ){
            for( int k = 0; k < p; k++ )
                if( vis[j][k] == 1 )
                    cnt++;
        }
        cout<<"Case "<<i+1<<": "<<cnt<<endl;
    }

}
