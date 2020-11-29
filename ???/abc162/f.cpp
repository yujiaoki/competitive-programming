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
    int n; cin >> n;
    ll ans = 0;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int pick_num = floor((double)n/2);
    // vector<ll> b(n);
    // rep(i,n) b[i] = a[i];
    // sort(b.begin(),b.end());
    while(pick_num){
        ll ma = -INF;int ind = -1;
        rep(i,a.size()){
            if (a[i] > ma){
                ma = a[i];
                ind = i;
            }
        }
        ans += ma;
        if(ind == 0){
            a.erase(a.begin());
            a.erase(a.begin());
        }
        else if(ind == a.size()-1){
            a.erase(a.end());
            a.erase(a.end());
        }
        else{
            a.erase(a.begin()+ind-1);
            a.erase(a.begin()+ind-1);
            a.erase(a.begin()+ind-1);
        }
        // ans += b[b.size()-1];
        // b.pop_back();b.pop_back();
        pick_num--;
    }
    cout << ans << endl;
}
