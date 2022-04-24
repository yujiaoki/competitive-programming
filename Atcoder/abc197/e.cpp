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
    vi l(n,INF),r(n,-INF);
    rep(i,n) {
        int x,c; cin >> x >> c;
        --c;
        l[c] = min(l[c],x);
        r[c] = max(r[c],x);
    }
    vpii d;
    d.emplace_back(0,0);
    rep(i,n) if (l[i] != INF) d.emplace_back(l[i],r[i]);
    d.emplace_back(0,0);
    vll dp(2);
    const ll LINF = 1ll<<60;
    FOR(i,1,d.size()-1) {
        vll p(2, LINF);
        // すぬけ式 dp
        swap(p,dp);
        int l = d[i].first, r = d[i].second; // サタンとうたんを取り出す
        rep(j,2) {
            int x = j ? d[i-1].second : d[i-1].first; // 前々の左端or右端を取り出す(jによる) 現在地、
            dp[0] = min(dp[0], p[j] + abs(x-r) + r - l); // 左端　で終わる. (先に右に行く)
            dp[1] = min(dp[1], p[j] + abs(x-l) + r - l); // 右端　で終わる。(先に左に行く)
        }
    }
    cout << dp[0] << endl;
}
