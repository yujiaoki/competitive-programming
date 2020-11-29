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
using namespace std;
typedef long double ld;
typedef unsigned long long int ull;
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
typedef pair<int,int> P;
vi w(1e6 + 10, 0);
 int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
// gcdも呼ぶ！！！
int ngcd(vector<int>& a) {
    int d = a[0];
    for (int i = 1; i < a.size() && d != 1; i++) d = gcd(a[i], d);
    return d;
}
void enum_div(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            // ret.push_back(i);
            w[i]++;
            // if (w[i] > 1) return 0;
            if (w[i] > 1) return;
            if (i != 1 && i * i != n) {
                // ret.push_back(n/i);
                w[n / i]++;
                if (n / i > 1 && w[n / i] > 1) return;
            }
        }
    }
    w[n]++;
    // if (w[n] > 1) return 0;
    // return 1;
}

int main(void){
    // Your code here!
    int n;cin >> n;
    vi v(n);
    string ans = "";
    rep(i,n) cin >> v[i];
    if (ngcd(v)!=1) {
        ans = "not coprime";
    } else {
        bool ch = 1;
        rep(i,n) {enum_div(v[i]);}
        for (int i = 2; i < w.size(); i++) {
            if (w[i] > 1) {
                ch = 0;
                break;
            }
        }
        if (ch) ans = "pairwise coprime";
        else ans = "setwise coprime";
    }
    cout << ans << endl;
}
