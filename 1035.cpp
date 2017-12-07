#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define M 100

ll dp[M+1];
bool is_prime[M+1];

ll arr[M+1];


void sieve(ll n)
{
    memset(is_prime,true,sizeof is_prime);

    is_prime[0]=false;
    is_prime[1]=false;

    for(ll i=2;i*i<=n;i++)
    {
        if(is_prime[i]==true)
        {
            for(ll j=i*i;j<=n;j+=i)
            {
                is_prime[j]=false;
            }
        }
    }
}



void ppf(ll n)
{
    ll x=2;
    while(n>1)
    {
        ll c=0;
        if(is_prime[x])
        {
            while(n%x==0)
            {
                n/=x;
                c++;
            }
            arr[x]+=c;
        }
        x++;
    }
}

void go(ll n)
{
    ll temp=n;
    memset(arr,0,sizeof arr);
    while(n--)
    {
        ppf(n+1);
    }
    ll x=2;
    while(x<=temp)
    {
        if(arr[x]!=0)
        {
            if(x==2)cout<<x<<" "<<"("<<arr[x]<<")";
            else cout<<" * "<<x<<" "<<"("<<arr[x]<<")";
        }
        x++;
    }
    cout<<endl;
}


int main()
{
    sieve(100);
    ll t;
    cin>>t;

    for(ll x=1;x<=t;x++)
    {
        ll i;
        cin>>i;
        cout<<"Case "<<x<<": "<<i<<" = ";
        go(i);
    }

    return 0;
}
