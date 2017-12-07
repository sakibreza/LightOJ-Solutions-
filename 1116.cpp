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
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    for(ll ks=1;ks<=t;ks++)
    {
        ll n;
        scanf("%lld",&n);
        printf("Case %lld: ",ks);
        if(n%2)
            printf("Impossible\n");
        else
        {
            for(ll i=2;;i+=2)
            {
                if((n%i==0)&&((n/i)%2))
                {
                    printf("%lld %lld\n",n/i,i);
                    break;
                }
            }
        }
    }
    return 0;
}
