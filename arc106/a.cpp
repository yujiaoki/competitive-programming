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
    ll n; cin >> n;
    bool res = false;
    // ll ans_a = -1,ans_b = -1;
    // ll a_max = 0,b_max = 0;
    // while(pow(3,a_max) < pow(10,18)) {
    //     a_max++;
    // }
    // while(pow(5,b_max) < pow(10,18)) {
    //     b_max++;
    // }
    // ll A = 1,B = 1;
    // rep(a,a_max) {
    //     rep(b,b_max) {
    //         if (pow(3,a)+pow(5,b) == n) {
    //             res = true;
    //             ans_a = a;
    //             ans_b = b;
    //         }
    //     }
    // }ll
    int ans_a = 0,ans_b = 0;
    for (ll b = 5; b < n; b*=5) {
        ans_b++;
        // if (n- pow(5,b) <= 0 || pow(5,b) <= 0) break;
        // ll A = n- pow(5,b);
        // if (A < 0) break;
        // while(true) {
        //     if (A % 3 != 0) {
        //         cnt = false;
        //         break;
        //     }
        //     A/=3;
        //     if (A == 1) break;
        // }
        ans_a = 0;
        for (ll a = 3; a + b <= n;a*=3) {
            ans_a++;
            if (a + b == n) {
                res = true;
                cout << ans_a << " " << ans_b << endl;
                return 0;
            }
            // if (pow(3,a) > A || pow(3,a) < A ) break;
            // if (pow(3,a) == A) {
            //      ans_a = a;
            // ans_b = b;
            // res = true;
            // break;
            // }
        }
    }
    // if (res) cout << ans_a << " " << ans_b << endl;
    cout << -1 << endl;
}
