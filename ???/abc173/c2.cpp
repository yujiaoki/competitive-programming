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
    int h,w,k; cin >> h >> w >> k;
    vector<vector<char>> c(h,vector<char>(w));
    rep(i,h) {
        rep(j,w) cin >> c[i][j];
    }
    ll ans = 0;
    // rep(i,h) {
    //     rep(j,w) {
    //         ll cnt = 0;
    //         rep(k,h) {
    //             rep(l,w) {
    //                 if(k == i || l == j) continue;
    //                 if(c[k][l] == '#') cnt++;
    //             }
    //         }
    //         if(cnt == k) {
    //             cout << i <<" " << j << endl;
    //             ans++;
    //         }
    //     }
    // }
    for (int bit_h = 0;bit_h <(1<<h);++bit_h) {
        for (int bit_w = 0;bit_w <(1<<w);++bit_w) {
            ll cnt = 0;
            rep(i,h) {
                rep(j,w) {
                    if(bit_h &(1<<i) || bit_w & (1<<j)) continue;
                    if(c[i][j] == '#') cnt++;
                }
            }
            if (cnt == k) ans++;
        }
    }
    
    cout << ans << endl;
}
