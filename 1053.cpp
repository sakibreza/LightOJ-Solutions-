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
        ll a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        ll mx=max(a,max(b,c));
        ll mn=min(a,min(b,c));
        ll md=a+b+c-mx-mn;

        if(mx*mx==md*md+mn*mn)
            printf("Case %lld: yes\n",ks);
        else
            printf("Case %lld: no\n",ks);
    }
    return 0;
}
