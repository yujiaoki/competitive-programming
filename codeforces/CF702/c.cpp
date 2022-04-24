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
//---------------------------------------------------------------------------------------------------
bool is_integer(long double x ){
  return std::floor(x)==x;
}
double cbrt_newton(double a, double x) {
    double e;

    do {
        e = (x * x * x - a) / (3.0 * x * x);
        x = x - e;
    } while ( fabs(e) > 1.0e-16 );

    return x;
}
void solve() {
    ll x ; cin >> x;
    if (x == 1) {
        cout << "NO" << endl;
        return;
    }
    // FOR(a,1,1e4) FOR(b,1,1e4) {
    //     if (pow(a,3) + pow(b,3) == x) {
    //         cout << "YES" << endl;
    //         return ;
    //     }
    // }
    // cout << "NO" << endl;
    FOR(a,1,1e4) {
        ll k = x - a*a*a;
        long double b = (long double)pow(k,1.0/3.0);
        // if (abs(b - round(b)) < 1e-10) {
            if (is_integer(b)) {
            cout << "YES" << endl;
            cout << setprecision(10) <<  b << endl;
            return;
        }
    }
    cout << "NO" << endl;
}


int main(void){
    // Your code here!
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
