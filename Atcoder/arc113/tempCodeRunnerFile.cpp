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
int a,b,c; 
int d[100][100] = {{1,1,1,1},{2,4,8,6},{3,9,7,1},{4,6,4,6},{5,5,5,5},{6,6,6,6},{7,9,3,1},{8,4,2,6},{9,1,9,1}};

int main(void){
    // Your code here!
    cin >> a >> b >> c;
    // ll l = d[(b+9)%10][(c+3)%4];
    ll l;
    if (b == 1 ||b == 5 ||b == 9 ) {
        l = 1;
    } else if (b == 2 || b == 6) {
        if (c > 1) l = 0;
        else l = 2;
    } else if (b == 4|| b == 8) {
        l = 0;
    } else if (b == 3 || b == 7) {
        if (c % 2  == 0) l = 1;
        else l = 3;
    }
    ll ans = d[(a+9)%10][(l+3)%4];
    cout << ans << endl;
}
