#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 5005
#define PI acos(-1.0)
#define Mn 1000000007

ll level[N];
ll level2[N];
vector<pair<ll,ll> >graph[N];

void dijkstra(ll source)
{
    level[source]=0;
    priority_queue<pair<ll,pair<ll,ll> > >q;
    q.push(mp(1,mp(0,source)));
    while(!q.empty())
    {
        pair<ll,pair<ll,ll> > temp=q.top();
        q.pop();
        ll u,uc,v,vc;

        ll flag=temp.first;
        u=temp.second.second;
        uc=-temp.second.first;
//
//        if(uc>level[u]) continue;

        ll tu;
        if(flag==1)tu=level[u];
        else if(flag==2)tu=level2[u];

        for(ll i=0;i<graph[u].size();i++)
        {
            v=graph[u][i].second;
            vc=graph[u][i].first;
//            cout<<v<<" "<<vc<<endl;

//            cout<<level[v]<<" "<<level[u]+vc<<endl;

            if(level[v]>(tu+vc))
            {
                level2[v]=level[v];
                level[v]=tu+vc;
                q.push(mp(1,mp(-level[v],v)));
                q.push(mp(2,mp(-level2[v],v)));
            }
            else if(level[v]<(tu+vc) && level2[v]>(tu+vc))
            {
//                cout<<"t"<<endl;
                level2[v]=tu+vc;
//                cout<<v<<" "<<level2[v]<<endl;
                q.push(mp(2,mp(-level2[v],v)));
//                cout<<">> "<<level2[v]<<endl;
            }
        }
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll T,n,m,s,t;
    cin>>T;
    for(ll ks=1;ks<=T;ks++)
    {
        for(ll i=0;i<N;i++) level[i]=1000000000;
        for(ll i=0;i<N;i++) level2[i]=1000000000;
        for(ll i=0;i<N;i++) graph[i].clear();

        cin>>n>>m;

        while(m--)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            graph[a].pb(mp(c,b));
            graph[b].pb(mp(c,a));
        }

        dijkstra(1);

//        cout<<level[t]<<endl;


        printf("Case %lld: %lld\n",ks,level2[n]);

    }

    return 0;

}
