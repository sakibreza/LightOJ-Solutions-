#include<bits/stdc++.h>

using namespace std;

int s[100005],n,q;

int lo_bi(int x)
{
    int lo=0,up=n-1,mid=0;
    while(lo<=up)
    {
        mid=(lo+up)/2;
        if(s[mid]<x) lo=mid+1;
        else if(s[mid]>x) up=mid-1;
        else return mid;
    }

    return lo;
}

int up_bi(int x)
{
    int lo=0,up=n-1,mid=0;
    while(lo<=up)
    {
        mid=(lo+up)/2;
        if(s[mid]<=x) lo=mid+1;
        else up=mid-1;
    }
    return lo;
}

int main()
{

    int t;
    cin>>t;

    for(int x=1;x<=t;x++)
    {
        printf("Case %d:\n",x);
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++) scanf("%d",&s[i]);
        for(int i=0;i<q;i++)
        {
            int lo,up;
            scanf("%d %d",&lo,&up);
            printf("%d\n",up_bi(up)-lo_bi(lo));
        }
    }

    return 0;
}
