#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll)1e18

ll sum[400005];
ll arr[100005];

void build(ll node,ll l,ll r)
{
    if(l==r)
        sum[node]=arr[l];
    else
    {
        ll mid=(l+r)/2;
        build(node*2,l,mid);
        build(node*2+1,mid+1,r);
        sum[node]=sum[node*2]+sum[node*2+1];
    }
}

ll query(ll node,ll L,ll R,ll l,ll r)
{
    if(r<L||R<l) return 0;
    if(l<=L&&r>=R) return sum[node];

    ll mid=(L+R)/2;
    ll x=query(node*2,L,mid,l,r);
    ll y=query(node*2+1,mid+1,R,l,r);

    return x+y;
}

void update(ll node,ll l,ll r,ll pos,ll value)
{
    if(l==r)
    {
        sum[node]=value;
        return;
    }

    ll mid=(l+r)/2;
    if(pos<=mid)
        update(node*2,l,mid,pos,value);
    else
        update(node*2+1,mid+1,r,pos,value);
    sum[node]=sum[node*2]+sum[node*2+1];
}

void update2(ll node,ll l,ll r,ll pos,ll value)
{
    if(l==r)
    {
        sum[node]+=value;
        return;
    }

    ll mid=(l+r)/2;
    if(pos<=mid)
        update2(node*2,l,mid,pos,value);
    else
        update2(node*2+1,mid+1,r,pos,value);
    sum[node]=sum[node*2]+sum[node*2+1];
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll t;
    scanf("%lld",&t);
    for(ll ks=1;ks<=t;ks++)
    {
        ll n,q;
        scanf("%lld %lld",&n,&q);
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
        }

        build(1,1,n);
        printf("Case %lld:\n",ks);
        while(q--)
        {
            ll tok,l,r;
            scanf("%lld",&tok);
            if(tok==1)
            {
                scanf("%lld",&l);
                printf("%lld\n",query(1,1,n,l+1,l+1));
                update(1,1,n,l+1,0);
            }

            else if(tok==2)
            {
                scanf("%lld %lld",&l,&r);
                update2(1,1,n,l+1,r);
            }

            else if(tok==3)
            {
                scanf("%lld %lld",&l,&r);
                printf("%lld\n",query(1,1,n,l+1,r+1));
            }
        }
    }

    return 0;
}
