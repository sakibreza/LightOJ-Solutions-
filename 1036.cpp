#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll)1e9+7
#define INF 1e18

ll rad[502][502],ura[502][502];

ll dp[502][502];

ll go(ll i,ll j)
{
    if(i<=0||j<=0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    ll res1=ura[i][j]+go(i-1,j);
    ll res2=rad[i][j]+go(i,j-1);

    dp[i][j]=max(res1,res2);

    return dp[i][j];
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll t,k=0;
    cin>>t;
    while(t--)
    {
        memset(rad,0,sizeof rad);
        memset(ura,0,sizeof ura);
        memset(dp,-1,sizeof dp);
        k++;
        ll n,m;
        cin>>n>>m;

        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
            {
                ll a;
                cin>>a;
                ura[i][j]=ura[i][j-1]+a;
            }
        }

        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
            {
                ll a;
                cin>>a;
                rad[i][j]=rad[i-1][j]+a;
            }
        }

        cout<<"Case "<<k<<": "<<go(n,m)<<endl;

    }
    return 0;
}

