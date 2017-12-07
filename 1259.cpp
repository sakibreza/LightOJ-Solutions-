#include<bits/stdc++.h>

using namespace std;

#define M 10000000

bool marked[M];
vector<int>v;

bool isPrime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  return marked[n] == false;
}

void sieve(int n) {
  for(int i=4;i<=n;i+=2) marked[i]= true;
  for (int i = 3; i * i <= n; i += 2) {
    if (marked[i] == false) {
      for (long long j = i * i; j <= n; j += i + i) {
        marked[j] = true;
      }
    }
  }
}

int main()
{
    int n,t;
    cin>>t;
    sieve(10000000);
    for(int l=1;l<=t;l++)
    {
        cin>>n;
        int c=0;
        //sieve(n);

        for(int x=2;x<=n/2;x++)
        {
            int f=n-x;
            if(isPrime(f)&&isPrime(x))
            {
                //cout<<n<<" = "<<min(f,x)<<" + "<<max(f,x)<<endl;
                c++;
            }
        }
        cout<<"Case "<<l<<": "<<c<<endl;

    }
}

