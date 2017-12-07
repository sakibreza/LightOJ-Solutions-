#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define M 5000001

ll phi[M];

void EPhi()
{
    for(ll i=2;i<M;i++)
    {
        if(!phi[i]==1)
        {
            phi[i]=i-1;
            for(ll j=i*2;j<M;j+=i)
            {
                if(!phi[j]==1)
                {
                    phi[j]=j;
                }
                phi[j]-=(phi[j]/i);
            }
        }
    }

    for(ll i=2;i<M;i++)
    {
        phi[i]*=phi[i];
        phi[i]+=phi[i-1];
    }
}



int main()
{
    EPhi();
    ll t;
    cin>>t;

    for(ll x=1;x<=t;x++)
    {
        ll a,b;
        scanf("%llu%llu",&a,&b);
        printf("Case %d: %llu\n",x,phi[b]-phi[a-1]);
    }

    return 0;
}
