#include <bits/stdc++.h>
// #include<atcoder/all>
// using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
typedef long long ll;
// const ll MOD=1000000007;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// template<class T>auto MAX(const T& a) { return *max_element(a.begin(),a.end()); }
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
long long com[51][51];

int main(void){
    // Your code here!
    com[0][0] = 1;
    for (int i = 1; i < 51; ++i) {
        for (int j = 0; j <= i; ++j) {
            com[i][j] += com[i-1][j];
            if (j > 0) com[i][j] += com[i-1][j-1];        
        }
    }
    int n,a,b; cin >> n >> a >> b;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    Rort(v);

    ll sum =0;
    rep(i,a) sum += v[i];
    double ave = (double)(sum)/a;

    ll res = 0;
    int num = 0;
    rep(i,n) if (v[i] == v[a-1]) num++;
    if (v[0] == v[a-1]) {
        FOR(j,a,b) {
            res += com[num][j];
        }
    } else {
        int aa = 0;
        rep(i,a) if (v[i] == v[a-1]) aa++;
        res += com[num][aa];
    }
    cout << setprecision(10) << ave << endl;
    cout << res << endl;
    // map<ll,int> mp;
    // rep(i,n) {
    //     ll s; cin >> s;
    //     mp[s]++;
    //     if (find(all(v),s) == v.end()) v.push_back(s);
    // }
    // Rort(v);
    // ll ans = 0;
    // int now = 0;
    // int count = a;
    // int pattern = 0;
    // while(count > 0) {
    //     if (mp[v[now]] < count) {
    //         ans += v[now]*mp[v[now]];
    //         count -= mp[v[now]];
    //     } else {
    //         ans += v[now]*count;
    //         pattern = COM(mp[v[now]],count);
    //         break;
    //     }
    //     now++;
    // }
    // cout << setprecision(20) << (double)ans/a << endl;
    // cout << pattern << endl;
}
