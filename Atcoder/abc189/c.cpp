#include <bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
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
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
typedef vector<vll> vvll;
typedef map<int, int> mii;
typedef set<int> si;
//---------------------------------------------------------------------------------------------------

int main(void){
    // Your code here!
    int n; cin >> n;
    vll a(n);
    rep(i,n) cin >> a[i];
    ll res = 0;
    vll c = a;
    Sort(c);
    rep(i,n) {
        ll mi = c[i];
        ll now = 0;
        rep(j,n) {
            if (mi <= a[j]) {
                now += mi;
                res = max(res,now);
            } else {
                now = 0;
                res = max(res,now);
            }
        }
    }
    cout << res << endl;
    // ll now = 0;
    // int right = 0;
    // for (int left = 0; left < n; ++left) {
    //     ll mi = a[left];
    //     now = mi*max(0,(right-left-1));
    //     while(right < n && mi <= a[right]) {
    //         now += mi;
    //         right++;
    //     }
    //     res = max(res,now);
    //     if (left == right) ++right;
    // }
    // cout << res << endl;

    // vll b(n,0);
    // ll mi = INF;
    // vll c = a; //c = sort
    // Sort(c);
    // rep(i,n) {
    //     mi = min(mi,a[i]);
    //     b[i] = mi;
    // }
}
