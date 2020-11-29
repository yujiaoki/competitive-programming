#include <bits/stdc++.h>
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

int main(void){
    // Your code here!
    int n; cin >> n;
    vi x(n),y(n),z(n);
    rep(i,n) cin >> x[i] >> y[i] >> z[i];
    int n2 = 1<<n;
    vvi dp(n2,vector<int>(n,INF));
    vvi dist(n,vector<int>(n));
    rep(i,n) rep(j,n) {
        int now = abs(x[i]-x[j]);
        now += abs(y[i]-y[j]);
        now += max(0,z[j]-z[i]);
        dist[i][j] = now;
    }
    rep(i,n) {
        if (i == 0) continue;
        dp[1<<i][i] = dist[0][i];
    } 
    rep(i,n2) rep(j,n) {
        if (!(i>>j & 1))continue;
        rep(k,n) {
            if (i>>k & 1) continue;
            chmin(dp[i|1<<k][k],dp[i][j]+dist[j][k]);
        }
    }
    cout << dp[n2-1][0] << endl;
}
