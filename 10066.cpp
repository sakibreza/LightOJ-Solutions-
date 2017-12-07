#include<bits/stdc++.h>

using namespace std;

int dp[102][102];
int n1, n2;

int lcs_length(int a[],int b[])
{
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }

    return dp[n1][n2];
}

int lcs(int a[],int b[],int n1,int n2)
{
   if (n1==0||n2==0) return 0;
   if (a[n1-1]==b[n2-1]) return 1+lcs(a,b,n1-1,n2-1);
   else return max(lcs(a,b,n1,n2-1),lcs(a,b,n1-1,n2));
}

int main()
{
    int a[102],b[102],c=1;
    while(cin>>n1>>n2&&n1&&n2)
    {
        memset(dp,0,sizeof dp);
        for(int x=0;x<n1;x++)cin>>a[x];
        for(int x=0;x<n2;x++)cin>>b[x];
        cout<<"Twin Towers #"<<c++<<endl;
        cout<<"Number of Tiles : "<<lcs_length(a,b)<<endl<<endl;
    }

    return 0;
}
