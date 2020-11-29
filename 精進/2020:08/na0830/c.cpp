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
typedef pair<int,int> P;

int main(void){
    // Your code here!
    int n; cin >> n;
    ll k; cin >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i],a[i]--;
    int x = 0;
    vector<int> ord(n,-1);
    ord[0] = 0;
    int first = 0;
    int cnt = 0;
    int roop;
    while(true) {
        cnt++;
        x = a[x];
        if (ord[x] != -1) {
            roop = cnt - ord[x];
            first = ord[x];
            break;
        }
        ord[x] = cnt;
    }
    if (k <= first) {
        rep(i,n) if (k == ord[i]) cout << i+1 << endl;return 0;
    } else {
        k -= first;
        k %= roop;
        rep(i,n) if (k == ord[i] - first) cout << i+1 << endl;return 0;
    }
}
