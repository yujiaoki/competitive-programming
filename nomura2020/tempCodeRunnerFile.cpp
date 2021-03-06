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

int main(void){
    // Your code here!
    string s;cin >> s;
    ll ans = 0;
    rep(i,s.size()-1){
        if (s[i] == 'P' && s[i+1] == '?'){
            ans++;
            s[i+1] = 'D';
        } else if (s[i] == '?' && s[i+1] == 'D') {
            s[i] = 'P';
        } else if (s[i] == '?' && s[i+1] == '?') {
            ans++;
            s[i] = 'P';
            s[i+1] = 'D';
        } else if (s[i] == '?' && s[i+1] == 'P') {
            s[i] = 'D';
        } else if (i == s.size() -2 && s[i] == 'D' && s[i+1] == '?') {
            s[i+1] = 'D';
        }
    }
    rep(i,s.size()) {
        if(s[i] == 'D') ans++;
    }
    cout << s << endl;
    // cout << ans << endl;
}
