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
ll mod_pow(ll x,ll n){
    if(n==0) return 1;
    ll res=mod_pow(x*x,n/2);
    if(n&1) res=res*x;
    return res;
}
int main(void){
    // Your code here!
    int n; cin >> n;
    if(n == 0) {
        ll a0;
        cin >> a0;
        if(a0==1) cout << 1 ;
        else cout << -1;
        return  0;
    }
    ll sum = 0;
    vector<int> a(n+1);
    rep(i,n+1) {
        cin >> a[i];
        sum += a[i];
    }
    if(a[0]!=0) {
        cout << -1 << endl;
        return 0;
    }
    ll leaf = 1;
    ll ans = 1;
    FOR(i,1,n) {
        if(leaf*2 > sum) leaf = sum;
        else leaf*=2;
        ans += leaf;
        leaf -= a[i];
        sum -= a[i];
        if(i!=n&&leaf<=0) {
            cout << -1 << endl;
            return 0;
        }
        if(i == n && leaf!=0) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
