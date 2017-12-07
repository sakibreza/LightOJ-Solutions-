#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M 1000003

ll fact[1000006];
ll x,y,gcd;
void ExEuclid(ll a,ll b){
    if(b==0)
    {
         gcd=a;
         x=1;
         y=0;
    }
    else
    {
         ExEuclid(b,a%b);
         int temp=x;
         x=y;
         y=temp-(a/b)*y;
    }
}

int main()
{
    fact[0]=1;
    for(ll i=1;i<=1000001;i++)
    {
        fact[i]=(i*fact[i-1])%M;
//        cout<<fact[i]<<endl;
    }
    ll t;
    cin>>t;
    for(ll ks=1;ks<=t;ks++)
    {
        ll n,k;
        cin>>n>>k;
        ll res1=fact[n]%M;
        ll res2=((fact[n-k]%M)*(fact[k]%M))%M;
        ExEuclid(res2,M);
        res2=(x%M+M)%M;
        cout<<"Case "<<ks<<": "<<res1*res2%M<<endl;
    }
}
