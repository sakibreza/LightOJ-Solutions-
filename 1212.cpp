#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M 1000000007


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ll t;
    cin>>t;
    for(ll k=1;k<=t;k++)
    {
        cout<<"Case "<<k<<":"<<endl;
        deque<ll>d;
        ll n,m;
        cin>>n>>m;
        while(m--)
        {
            string s;
            ll a;
            cin>>s;
            if(s=="pushLeft")
            {
                cin>>a;
                if(d.size()==n)cout<<"The queue is full"<<endl;
                else
                {
                    d.push_front(a);
                    cout<<"Pushed in left: "<<a<<endl;
                }
            }

            else if(s=="pushRight")
            {
                cin>>a;
                if(d.size()==n)cout<<"The queue is full"<<endl;
                else
                {
                    d.push_back(a);
                    cout<<"Pushed in right: "<<a<<endl;
                }
            }

            else if(s=="popLeft")
            {
                if(d.size()==0)cout<<"The queue is empty"<<endl;
                else
                {
                    cout<<"Popped from left: "<<d.front()<<endl;
                    d.pop_front();
                }
            }

            else if(s=="popRight")
            {
                if(d.size()==0)cout<<"The queue is empty"<<endl;
                else
                {
                    cout<<"Popped from right: "<<d.back()<<endl;
                    d.pop_back();
                }
            }
        }
    }
    return 0;
}

