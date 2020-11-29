#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
typedef long long ll;
const ll MOD=1000000007;
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
template<int MOD> struct ModInt {
    static const int Mod = MOD; unsigned x; ModInt() : x(0) { }
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const { long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u); }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ostream& operator<<(ostream& st, const ModInt<MOD> a) { st << a.get(); return st; };
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r; }
typedef ModInt<1000000007> mint;
struct Ruisekiwa2D {
    int VH, VW;
    using T = int;
    vector<vector<T>> v;
    bool needBuild = false;
    Ruisekiwa2D() { }
    Ruisekiwa2D(int w, int h) { init(w, h); }
    void init(int w, int h) { 
        needBuild = true;
        VH = h; VW = w;
        v.clear();
        v.resize(h, vector<T>(w));
        rep(y,VH) rep(x,VW) v[y][x] = 0; }
    void set(int x, int y, T c) { v[y][x] = c; }
    void add(int x, int y, T c) { v[y][x] += c; }
    void build() {
        rep(y,VH) rep(x,VW) {
            if (0 < y) v[y][x] += v[y - 1][x];
            if (0 < x) v[y][x] += v[y][x - 1];
            if (0 < y && 0 < x) v[y][x] -= v[y - 1][x - 1];
        }
        needBuild = false;
    }
    // [sx,sy]-[tx,ty]
    T get(int sx, int tx, int sy, int ty) {
        if (needBuild) assert(0 && "Need Build");
        if (tx < sx or ty < sy) return 0;
        T rs = v[ty][tx];
        if (0 < sx) rs -= v[ty][sx - 1];
        if (0 < sy) rs -= v[sy - 1][tx];
        if (0 < sx && 0 < sy) rs += v[sy - 1][sx - 1];
        return rs;
    }
 
 
    // getTo...
    enum { UP = 0, RIGHT, DOWN, LEFT };
    T getTo(int x, int y, int len, int to) {
        switch (to)
        {
            case UP: return getToUp(x, y, len);
            case RIGHT: return getToRight(x, y, len);
            case DOWN: return getToDown(x, y, len);
            case LEFT: return getToLeft(x, y, len);
        }
        assert(0);
    }
    T getToDown(int x, int y, int len) {
        if (needBuild) assert(0 && "Need Build");
        if (VH - y < len) len = VH - y;
        return get(x, x, y, y + len - 1);
    }
    T getToUp(int x, int y, int len) {
        if (needBuild) assert(0 && "Need Build");
        if (y + 1 < len) len = y + 1;
        return get(x, x, y - len + 1, y);
    }
    T getToRight(int x, int y, int len) {
        if (needBuild) assert(0 && "Need Build");
        if (VW - x < len) len = VW - x;
        return get(x, x + len - 1, y, y);
    }
    T getToLeft(int x, int y, int len) {
        if (needBuild) assert(0 && "Need Build");
        if (x + 1 < len) len = x + 1;
        return get(x - len + 1, x, y, y);
    }
};
//---------------------------------------------------------------------------------------------------
int H,W;
string S[2020];
mint pr[4101101];

int main(void){
    // Your code here!
    cin >> H >> W;
    rep(y,H) cin >> S[y];
    pr[0] = 1;
    FOR(i,1,4101100) pr[i] = pr[i-1]*2;
    Ruisekiwa2D emp(W,H);
    int K = 0;
    rep(y,H) rep(x,W) if (S[y][x] == '.') emp.add(x,y,1), K++;
    emp.build();

    mint ans = 0;
    rep(y,H) rep(x,W) if (S[y][x] == '.') {
        int cnt = 1;
        rep(d,4) {
            int ok = 1,ng = 2020;
            while(ok + 1 != ng) {
                int md = (ok+ng)/2;
                if (emp.getTo(x,y,md,d) == md) ok = md;
                else ng = md;
            }
            cnt += ok - 1;
        }
        ans += pr[K] - pr[K - cnt];
    }
    cout << ans << endl;
}
