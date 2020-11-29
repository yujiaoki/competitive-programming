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
long long combi(long long n, long long k) {
  if (n == k || k == 0)
    return 1;
  else {
    return combi(n - 1, k - 1) + combi(n - 1, k);
  }
}
int main(void){
    // Your code here!
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> ans(n,0);
    rep(i,n) cin >> a[i];
    map<ll,ll> mp;
    map<ll,ll> mp2;
    rep(i,n){
        mp[a[i]]++;
    }
    for ( auto x:mp){
        mp2[x.first] = x.second*(x.second-1)/2;
    }
    ll sum = 0;
    for (auto x:mp2){
        sum += x.second;
    }
    rep(i,n){
        if ( mp[a[i]] < 2) {
            cout << sum << endl;
            continue;
        }else if (mp[a[i]] == 2){
            cout << sum - 1 << endl;
        }else{
        ll res = sum - mp2[a[i]] + (mp[a[i]]-1)*(mp[a[i]]-2)/2;
        cout << res << endl;
        }
    }
}
