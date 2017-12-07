#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll) 1000000007

using namespace std;

ll ncr[1001][1001];
ll fact[1001];

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    fact[0]=1;
    fact[1]=1;
    for(ll i=2;i<=1000;i++)
    {
        fact[i]=(fact[i-1]*i)%M;
    }

    ncr[0][0]=1;

    for(ll i=1;i<=1000;i++)
    {
        ncr[i][0]=1;
        for(ll j=1;j<=i;j++)
        {
            ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%M;
        }
    }

    ll t;
    cin>>t;
    for(ll ks=1;ks<=t;ks++)
    {
        ll n,m,k;
        cin>>n>>m>>k;

        ll res=fact[n-k];

        for(ll i=1;i<=m-k;i++)
        {
            if(i%2==0)
                res+=(ncr[m-k][i]*fact[n-k-i])%M;
            else
                res-=(ncr[m-k][i]*fact[n-k-i])%M;

            res=(res+M)%M;

        }



        cout<<"Case "<<ks<<": "<<(ncr[m][k]*res)%M<<endl;
    }

    return 0;
}
