#include <bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
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
template<class T>auto MAX(const T& a) { return *max_element(a.begin(),a.end()); }
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

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

// https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396
const int mod = 998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

// // 二項係数ライブラリ
// template<class T> struct BiCoef {
//     vector<T> fact_, inv_, finv_;
//     constexpr BiCoef() {}
//     constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
//         init(n);
//     }
//     constexpr void init(int n) noexcept {
//         fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
//         int MOD = fact_[0].getmod();
//         for(int i = 2; i < n; i++){
//             fact_[i] = fact_[i-1] * i;
//             inv_[i] = -inv_[MOD%i] * (MOD/i);
//             finv_[i] = finv_[i-1] * inv_[i];
//         }
//     }
//     constexpr T com(int n, int k) const noexcept {
//         if (n < k || n < 0 || k < 0) return 0;
//         return fact_[n] * finv_[k] * finv_[n-k];
//     }
//     constexpr T fact(int n) const noexcept {
//         if (n < 0) return 0;
//         return fact_[n];
//     }
//     constexpr T inv(int n) const noexcept {
//         if (n < 0) return 0;
//         return inv_[n];
//     }
//     constexpr T finv(int n) const noexcept {
//         if (n < 0) return 0;
//         return finv_[n];
//     }
// };

// BiCoef<mint> bc;

mint solve(int n,ll k,const vvll &a) {
  UnionFind uf(n);
  rep(i,n) {
    FOR(j,i+1,n-1) {
      bool ok = true;
      rep(m,n) if (a[i][m] + a[j][m] > k) ok = false;
      if (ok) uf.merge(i,j);
    }
  }
  mint res = 1;
  rep(i,n) {
    if (uf.root(i) == i) {
      FOR(j,1,uf.size(i)) {
        res *= j;
      }
    }
  }
  return res;
}
int main(void){
    // Your code here!
    int n; 
    ll k;
    cin >> n >> k;
    vvll a(n,vector<ll>(n));
    rep(i,n) rep(j,n) cin >> a[i][j];
    mint res1 = solve(n,k,a);
    rep(i,n) FOR(j,i+1,n-1) swap(a[i][j],a[j][i]);
    mint res2 = solve(n,k,a);
    cout << res1*res2 << endl;
}
