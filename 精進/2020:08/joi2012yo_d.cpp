#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
typedef long long ll;
const int MOD=1000000007;
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

using P = pair<int,int>;
int dp[101][3][3] = {0};

int main(void){
    // Your code here!
    int n,k; cin >> n >> k;
    vector<int> f(n,-1);
    rep(i,k) {
        int a,b;
        cin >> a >> b;
        f[a-1] = b - 1;
    }
    dp[0][0][0] = 1;
    rep(i,n) rep(a,3) rep(b,3) {
        vector<int> cs = {0,1,2};
        if (f[i] >= 0) cs = {f[i]};

        for (int c:cs) {
            if (i >= 2 && a == b && b == c) continue;
            dp[i+1][b][c] += dp[i][a][b];
            dp[i+1][b][c] %= 10000;
        }
    }

    ll ans = 0;
    rep(a,3) rep(b,3) {
        ans += dp[n][a][b];
        ans %= 10000;
    }
    cout << ans << endl;
}
