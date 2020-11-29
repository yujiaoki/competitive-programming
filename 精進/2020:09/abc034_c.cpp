#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
 
const ll MOD = (ll)1e9 + 7;
const ll HIGHINF = (ll)1e18;
 
// aのb乗をmで割った余りを返す関数
// ll inv_elm(ll a, ll b, ll m) {
//   if (b == 0) return 1LL;
//   else if (b % 2 == 1) return (a * inv_elm(a, b-1, m)) % m;
//   else {
//     ll d = inv_elm(a, b / 2, m); return (d * d) % m;
//   }
// }
ll RepeatSquaring(ll N, ll P, ll M){
    if(P==0) return 1LL;
    else if (P % 2 == 1) return (N * RepeatSquaring(N,P-1,M)) % M;
    else {
        ll t = RepeatSquaring(N, P/2, M);
        return t*t % M;
    }
}
//--------------------------------------------------------------------------------------------

int main(void){
    // Your code here!
    ll w,h; cin >> w >> h;
    ll ans = 1;
    for (ll i = w + h - 2; i > max(w-1,h - 1); i--) {
        ans *= i; 
        ans %= MOD;
    }
    for (ll i = 2; i <= min(w-1,h-1); i++) {
        ans *= RepeatSquaring(i,MOD-2,MOD);
        ans %= MOD;
    }
    cout << ans << endl;
}
