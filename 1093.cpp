#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M 1000000007

ll res=-1;

void slide_rmq(vector<ll> &arr,ll k)
{
    res=-1;
    deque<pair<ll,ll> > window_min,window_max;
    for(ll i=0;i<arr.size();i++)
    {
        while(!window_min.empty()&&window_min.back().first>=arr[i])
            window_min.pop_back();
        while(!window_max.empty()&&window_max.back().first<=arr[i])
            window_max.pop_back();

        window_max.push_back(mp(arr[i],i));
        window_min.push_back(mp(arr[i],i));

        while(window_min.front().second<=i-k)
            window_min.pop_front();
        while(window_max.front().second<=i-k)
            window_max.pop_front();

        //cout<<window_max.front().first<<" "<<window_min.front().first<<endl;
        res=max(abs(window_max.front().first-window_min.front().first),res);

    }
}

int main()
{
    ll t;
    scanf("%lld",&t);
    for(ll k=1;k<=t;k++)
    {
        vector<ll>v;
        ll n,d;
        scanf("%lld %lld",&n,&d);
        for(ll i=0;i<n;i++)
        {
            ll a;
            scanf("%lld",&a);
            v.pb(a);
        }
        slide_rmq(v,d);
        printf("Case %lld: %lld\n",k,res);
    }
}
