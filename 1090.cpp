#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<ll,ll> fact_two_five(ll n)
{
    ll c2=0,c5=0;
    ll p=5;
    while(floor(n/(p*1.0)))
    {
        c5+=floor(n/(p*1.0));
        p*=5;
    }

    p=2;
    while(floor(n/(p*1.0)))
    {
        c2+=floor(n/(p*1.0));
        p*=2;
    }

    return make_pair(c2,c5);
}

pair<ll,ll> pow_two_five(ll p,ll q)
{
    ll temp=p;
    ll c2=0,c5=0;
    while(p%2==0)
    {
        p/=2;
        c2++;
    }

    while(temp%5==0)
    {
        temp/=5;
        c5++;
    }

    c2*=q; c5*=q;

    return make_pair(c2,c5);
}

void solve(ll t)
{
    ll n,r,p,q,two=0,five=0;
    scanf("%lld %lld %lld %lld",&n,&r,&p,&q);
//    p=10,q=4;
    pair<ll,ll>pr;
    pr=pow_two_five(p,q);
    two+=pr.first; five+=pr.second;

//    cout<<pr.first<<" "<<pr.second<<endl;
//    cout<<two<<" "<<five<<endl<<endl;

    pr=fact_two_five(n);
    two+=pr.first; five+=pr.second;

//    cout<<pr.first<<" "<<pr.second<<endl;
//    cout<<two<<" "<<five<<endl<<endl;

    pr=fact_two_five(r);
    two-=pr.first; five-=pr.second;

//    cout<<pr.first<<" "<<pr.second<<endl;
//    cout<<two<<" "<<five<<endl<<endl;

    pr=fact_two_five(n-r);
    two-=pr.first; five-=pr.second;
//
//    cout<<pr.first<<" "<<pr.second<<endl;
//
//    cout<<two<<" "<<five<<endl<<endl;

    ll ans=min(two,five);

    printf("Case %lld: %lld\n",t,ans);
}

int main()
{
//    solve();
    ll t;
    cin>>t;

    for(ll x=0;x<t;x++)
    {
        solve(x+1);
    }

    return 0;
}
