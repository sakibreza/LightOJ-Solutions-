#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll)1e9+7

using namespace std;

int main()
{
    ll t;
    cin>>t;
    for(ll ks=1;ks<=t;ks++)
    {
        ll n;
        scanf("%lld",&n);
        ll cnt=__builtin_popcountll(n);
        if(cnt%2)
            printf("Case %lld: odd\n",ks);
        else
            printf("Case %lld: even\n",ks);
    }
    return 0;
}
