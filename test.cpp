#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
#define MAXX 5000003
typedef l
unsigned long long phi[MAXX];
int main()
{
    unsigned long long a,b,i,j;

    for(i=2;i<MAXX;i++){
        if(!phi[i]==1){
            phi[i]=i-1;
            for(j=i*2;j<MAXX;j+=i){
                if(!phi[j]==1){
                    phi[j]=j;
                }
                phi[j] -= (phi[j]/i);
            }
        }
    }
    for(i=2;i<MAXX;i++){
        phi[i] *=phi[i];
        phi[i]+=phi[i-1];
    }
    ll t;
    cin>>t;

    for(ll x=1;x<=t;x++)
    {
        ll a,b;
        cin>>a>>b;
        cout<<"Case "<<x<<": "<<phi[b]-phi[a-1]<<endl;
    }
    return 0;

}
