#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
typedef long long ll;
const ll MOD=1000000007;
using namespace std;

int main(void){
    ll n,k;
    cin >> n >> k;
    vector<ll> h(n+1);
    FOR(i,1,n) cin >> h.at(i);
    sort(h.begin(),h.end());
    rep(i,k-1) h.pop_back();
    if( n-k > 0) {
        ll attack = 0;
        rep(i,n-k+1){
            attack += h.at(i);
        }
        cout << attack << endl;
    }
    else cout << 0 << endl;
    
}