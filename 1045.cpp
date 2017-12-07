#include<bits/stdc++.h>

typedef long long ll;
#define M 1000006

using namespace std;

double dp[M];

void fact_log()
{
    dp[2]=2;

    for(ll x=2;x<M;x++)
    {
        dp[x]=dp[x-1]+log(x);
    }
}

int main()
{
    fact_log();

    int t;
    scanf("%lld",&t);

    for(ll x=0;x<t;x++)
    {
        ll n,b;
        scanf("%lld %lld",&n,&b);
        ll ans=(ll)ceil(dp[n]/log(b));
        if(n==0||n==1) ans=1;
        printf("Case %lld: %lld\n",x+1,ans);
    }

    return 0;
}
