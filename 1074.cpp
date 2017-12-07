#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 202
#define PI acos(-1.0)
#define Mn 1000000007
#define INF 10000000000000

ll W[N],dis[N];
vector<ll>u,v,cost;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    for(ll ks=1;ks<=t;ks++)
    {
        ll n;
        cin>>n;
        for(ll i=0;i<=n;i++)
        {
            W[i]=0;
            dis[i]=INF;
        }
        dis[1]=0;
        u.clear();v.clear();cost.clear();

        for(ll i=1;i<=n;i++) cin>>W[i];

        ll m;
        cin>>m;
        for(ll i=0;i<m;i++)
        {
            ll a,b;
            cin>>a>>b;
            u.pb(a);
            v.pb(b);
            ll temp=W[b]-W[a];
            cost.pb(temp*temp*temp);
//            cout<<"->"<<cost[i]<<endl;
        }

        for(ll i=1;i<=n;i++)
        {
            bool flag=0;
            for(ll j=0;j<m;j++)
            {
                ll a=u[j];
                ll b=v[j];
                if(dis[b]>dis[a]+cost[j])
                {
                    flag=1;
                    dis[b]=dis[a]+cost[j];
//                    cout<<">> "<<dis[a]<<" "<<cost[j]<<" "<<dis[b]<<endl;
                }
            }
            if(!flag) break;
        }

        cout<<"Case "<<ks<<":"<<endl;
        ll q;
        cin>>q;
        while(q--)
        {
            ll x;
            cin>>x;
            if(dis[x]<3||dis[x]>100005)
                cout<<"?"<<endl;
            else
                cout<<dis[x]<<endl;
        }
    }
}


