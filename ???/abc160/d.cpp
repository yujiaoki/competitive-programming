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
using Graph = vector<vector<ll>>;


int main(void){
    // Your code here!
    int n,x,y;cin >> n >> x >> y;
    Graph G(n+1);
    FOR(i,1,n){
        for (int j = i+1;j<=n ;j++){
                int cur = min(abs(j-i),abs(x-i)+1+abs(j-y));
                cur = min(cur,abs(y-i)+1+abs(j-x));
                G[i].push_back(cur);
            }
        }
    // rep(i,n+1){
    //     for(auto x:G[i]){
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    FOR(k,1,n-1){
        ll ans = 0;
        FOR(i,1,n){
            ans += count(G[i].begin(),G[i].end(),k);
        }
        cout << ans << endl;
    }
}
