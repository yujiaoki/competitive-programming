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

using P =pair<int,int>;
int main(void){
    // Your code here!
    int A,B,M; cin >> A >> B >> M;
    vector<int> a(A);
    vector<int> b(B);
    rep(i,A) cin >> a[i];
    rep(i,B) cin >> b[i];
    // map<P,int> mp;
    int res = INF;
    rep(i,M){
        int x,y,c; cin >> x >> y >> c;
        // P pair = {x-1,y-1};
        // mp[pair] = c;
        x--;y--;
        int cur = a[x]+b[y]-c;
        res = min(res,cur);
    }
    int nok = MIN(a)+MIN(b);
    res = min(res,nok);
    cout << res << endl;
}
