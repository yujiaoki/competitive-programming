#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
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

bool vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return true;
  }
  else { // 発見できなかったとき
    return false;
  }
}
int main(void){
    // Your code here!
    int n,m; cin >> n >> m;
    vector<int> a(m);
    vector<ll> dp(n+1,0);
    rep(i,m) {
        cin >> a[i];
        dp[a[i]] = -1;
    }
    if (a[0] == 1 && a[1] == 2) {
        cout << 0 << endl;
    }
    else {
        dp[0] = 1;
        if (a[0] == 1){
        dp[1] = 0;
            FOR(i,2,n){
                if (dp[i] == -1){
                    dp[i] = 0;
                }
                else {
                    dp[i] = dp[i-1]+dp[i-2];
                    dp[i]%=MOD;
                }
            }
        }
        else if (a[0] == 2){
            dp[1] = 1;
            dp[2] = 0;
            FOR(i,3,n){
                if (dp[i] == -1){
                    dp[i] = 0;
                }
                else {
                    dp[i] = dp[i-1]+dp[i-2];
                    dp[i]%=MOD;
                }
            }
        }
        else {
            dp[1] = 1;
            dp[2] = 2;
            FOR(i,3,n){
                if (dp[i] == -1){
                    dp[i] = 0;
                }
                else {
                    dp[i] = dp[i-1]+dp[i-2];
                    dp[i]%=MOD;
                }
            }
        }
        cout << dp[n]%MOD << endl;
    }
}
