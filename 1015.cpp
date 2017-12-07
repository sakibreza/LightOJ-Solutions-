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
        ll sum=0;
        for(ll i=0;i<n;i++)
        {
            ll a;
            scanf("%lld",&a);
            if(a>0) sum+=a;
        }

        printf("Case %lld: %lld\n",ks,sum);
    }
    return 0;
}
