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
    int n,k; cin >> n >> k;
    priority_queue<int> pl;
    priority_queue<int,vector<int>,greater<int>>mi;
    vector<int> zero;
    rep(i,n) {
        int a; cin >> a;
        if (a < 0) mi.push(a);
        else if (a == 0) zero.push_back(a);
        else pl.push(a);
    }
    ll cnt = k;
    ll ans = 1;
    if (cnt > 1 && pl.size() > 1 && mi.size() > 1) {
        int pl1 = pl.top();
        pl.pop();
        int pl2 = pl.top();
        pl.pop();
        int mi1 = mi.top();
        mi.pop();
        int mi2 = mi.top();
        mi.pop();
        if (pl1*pl2 > mi1*mi2) {
            ans *= pl1*pl2 ;
            ans %= MOD;
            mi.push(mi1);
            mi.push(mi2);
        } else {
            ans *= mi1*mi2 ;
            ans %= MOD;
            pl.push(pl1);
            pl.push(pl2);
        }
        cnt -= 2;
    } else if (cnt > 1 && mi.size() > 1) {
        int mi1 = mi.top();
        mi.pop();
        int mi2 = mi.top();
        mi.pop();
        ans *= mi1*mi2 ;
        ans %= MOD;
        cnt -=2;
    } else if (cnt > 0){
        int pl1 = pl.top();
        pl.pop();
        ans *= pl1;
        ans %= MOD;
        cnt--;
    }
    cout << ans << endl;
}
