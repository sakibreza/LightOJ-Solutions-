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
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ll t;
    cin>>t;
    for(ll k=1;k<=t;k++)
    {
        stack<string>f,b;
        b.push("http://www.lightoj.com/");
        string cmd,curr;
        cout<<"Case "<<k<<":"<<endl;
        while(cin>>cmd)
        {
            if(cmd=="VISIT")
            {
                while(!f.empty())
                {
                    f.pop();
                }

                cin>>curr;
                cout<<curr<<endl;
                b.push(curr);
            }

            else if(cmd=="BACK")
            {
                f.push(b.top());
                b.pop();
                if(b.size()==0)
                {
                    cout<<"Ignored"<<endl;
                    b.push(f.top());
                    f.pop();
                }
                else
                {
                    cout<<b.top()<<endl;
                }
            }

            else if(cmd=="FORWARD")
            {
                if(f.size()==0)
                {
                    cout<<"Ignored"<<endl;
                }
                else
                {
                    cout<<f.top()<<endl;
                    b.push(f.top());
                    f.pop();
                }
            }

            else if(cmd=="QUIT") break;

//            cout<<">> ";
//            if(b.size())cout<<b.top()<<" ";
//            else cout<<"- ";
//            if(f.size())cout<<f.top()<<" ";
//            else cout<<"- ";
//            cout<<endl;
        }
    }
    return 0;
}


