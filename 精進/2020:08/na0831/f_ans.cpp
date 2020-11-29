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
//---------------------------------------------------------------------------------------------------
typedef pair<string,string> P;

int main(void){
    // Your code here!
    int n; 
    string s; cin >> n >> s;
    int m = 2*n;
    string s1 = "",s2 = "";
    rep(i,n) s1 += s[i];
    rep(i,n) s2 += s[i+n];
    ll ans = 0;
    map<P,ll> mp;
    rep(i,1<<n) {
        string sw = "",sv = "";
        rep(j,n) {
            if (i >> j & 1) sw += s1[j];
            else sv += s1[j];
        }
        reverse(all(sv));
        ++mp[P(sw,sv)];
    }
    rep(i,1<<n) {
        string su = "",st = "";
        rep(j,n) {
            if (i >> j & 1) su += s2[j];
            else st += s2[j];
        }
        reverse(all(st));
        ans += mp[P(st,su)];
    }
    cout << ans << endl;
}
