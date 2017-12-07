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
        ll n,m,res;
        scanf("%lld %lld",&n,&m);
        if(n==1||m==1)
            res=n*m;
        else if(n==2||m==2)
        {
            ll p;
            if(n==2) p=m;
            else p=n;

            if(p%4==0) res=p;
            if(p%4==3) res=p+1;
            if(p%4==2) res=p+2;
            if(p%4==1) res=p+1;
        }

        else
            res=ceil(n*m/2.0);

        printf("Case %lld: %lld\n",ks,res);
    }
    return 0;
}
