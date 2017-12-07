#include<bits/stdc++.h>

using namespace std;

long long dp[100005],n;
int a,b,c,d,e,f;
long long fn( long long n )
{
    if(n==0) return a;
    if(n==1) return b;
    if(n==2) return c;
    if(n==3) return d;
    if(n==4) return e;
    if(n==5) return f;

    if(dp[n]!=-1)return dp[n];
    else return dp[n]=(fn(n-1)+fn(n-2)+fn(n-3)+fn(n-4)+fn(n-5)+fn(n-6))%10000007;
}


int main()
{
    int t;
    cin>>t;
    for(int x=0;x<t;x++)
    {
        memset(dp,-1,sizeof dp);
        cin>>a>>b>>c>>d>>e>>f>>n;
        cout<<"Case "<<x+1<<": "<<fn(n)%10000007<<endl;
    }
    return 0;

}
