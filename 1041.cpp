#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 102
#define PI acos(-1.0)
#define M (ll) 1000000007
#define INF 1e12

using namespace std;

ll id=0,cnt=0,total=0;

class edge
{
public:
    ll u,v,w;
    edge(ll x,ll y,ll z)
    {
        u=x,v=y,w=z;
    }
    bool operator<(const edge& e) const
    {
        return w<e.w;
    }
};

ll pr[N], rk[N];

ll find_(ll r)
{
    if(pr[r]==r) return r;
    else return find_(pr[r]);
}

void Union(ll a,ll b)
{
    if(rk[a]<rk[b])
        pr[a]=find_(b);
    else
    {
        pr[b]=find_(a);
        if(rk[a]==rk[b])
        rk[a]++;
    }
}

vector<edge>ed_lst;
map<string,ll>mp;

void MST()
{
    cnt=0;

    sort(ed_lst.begin(),ed_lst.end());

    total=0;
    for(ll i=0;i<ed_lst.size();i++)
    {
        ll u=ed_lst[i].u;
        ll v=ed_lst[i].v;
        ll w=ed_lst[i].w;

        ll a=find_(u);
        ll b=find_(v);

        if(a!=b)
        {
            cnt++;
            total+=w;
            Union(a,b);
        }
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;

    for(ll ks=1;ks<=t;ks++)
    {
        mp.clear();
        for(ll i=0;i<=N;i++)
            pr[i]=i,rk[i]=0;
        ed_lst.clear();
        id=1;
        ll k;
        cin>>k;
        while(k--)
        {
            string s1,s2;
            ll c;
            cin>>s1>>s2>>c;

            if(mp[s1]==0)
            {
                mp[s1]=id++;
            }

            if(mp[s2]==0)
            {
                mp[s2]=id++;
            }

            ed_lst.push_back(edge(mp[s1],mp[s2],c));
        }
        MST();
        cout<<"Case "<<ks<<": ";
        if(cnt==id-2)
            cout<<total<<endl;
        else
            cout<<"Impossible"<<endl;
    }


/**

2

12
Dhaka Sylhet 0
Ctg Dhaka 0
Sylhet Chandpur 9
Ctg Barisal 9
Ctg Rajshahi 9
Dhaka Sylhet 9
Ctg Rajshahi 3
Sylhet Chandpur 5
Khulna Rangpur 7
Chandpur Rangpur 7
Dhaka Rajshahi 6
Dhaka Rajshahi 7

2
Rajshahi Khulna 4
Kushtia Bhola 1

**/
