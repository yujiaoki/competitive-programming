#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
typedef long long ll;
const ll MOD=1000000007;
using namespace std;
ll GCD(ll x, ll y) {
    if ( y == 0) return x;
    else return GCD(y, x % y);
}

ll solve(int n,ll m,vector<ll> &a){
    bool same = true;
    while(a[0]%2==0){
        for(int i = 0;i < n;i++){
            if(a[i]%2 != 0)return 0;
            a[i]/=2;
        }
        m/=2;
    }
    rep(i,n) if(a[i]%2==0) return 0;

    ll lcm = 1;
    rep(i,n){
        ll g = GCD(lcm,a[i]);
        lcm = lcm/g*a[i];
        if(lcm > m) return 0;
    }
    return (m/lcm+1)/2;
}

int main(void){
    // Your code here!
   int n;ll m;cin >> n >> m;
   vector<ll> a(n);
   rep(i,n) cin >> a[i],a[i]/=2;
   cout << solve(n,m,a) << endl;
}
