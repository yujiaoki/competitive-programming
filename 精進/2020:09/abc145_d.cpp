#include <bits/stdc++.h>
// #include<atcoder/all>
// using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// template<class T>auto MAX(const T& a) { return *max_element(a.begin(),a.end()); }
template<class T>auto MIN(const T& a) { return *min_element(a.begin(),a.end()); }
template<class T, class U>U SUM(const T& a, const U& v) { return accumulate(a.begin(),a.end(), v); }
template<class T, class U>U COUNT(const T& a, const U& v) { return count(a.begin(),a.end(), v); }
template<class T, class U>int LOWER(const T& a, const U& v) { return lower_bound(a.begin(),a.end(), v) - a.begin(); }
template<class T, class U>int UPPER(const T& a, const U& v) { return upper_bound(a.begin(),a.end(), v) - a.begin(); }
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }
int LCM(int a, int b) { int g = GCD(a, b); return a / g * b; }
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
typedef vector<vll> vvll;
typedef map<int, int> mii;
typedef set<int> si;
//---------------------------------------------------------------------------------------------------
const int MAX = 10000000;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll RepeatSquaring(ll N, ll P, ll M){
    if(P==0) return 1LL;
    else if (P % 2 == 1) return (N * RepeatSquaring(N,P-1,M)) % M;
    else {
        ll t = RepeatSquaring(N, P/2, M);
        return t*t % M;
    }
}
int main(void){
    // Your code here!
    ll x,y; cin >> x >> y;
    if ((x+y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    if ((2*y - x) % 3 != 0 || (2*x-y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll a = (2*y-x)/3;
    ll b = (2*x-y)/3;
    // if (a == 0 || b == 0) {
    //     cout << 1 << endl;
    //     return 0;
    // }
    // ll ans = 1;
    // for (ll i = a + b; i > max(a,b); i--) {
    //     ans *= i;
    //     ans %= MOD;
    // }
    // for (ll i = 2; i <= min(a,b); i++) {
    //     ans *= RepeatSquaring(i,MOD-2,MOD);
    //     ans %= MOD;
    // }
    // cout << ans << endl;
    COMinit();
    cout << COM(a+b,b) << endl;
}
