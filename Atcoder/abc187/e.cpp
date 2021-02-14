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
// int G[20002][20002] = {0};

int main(void){
    int n; cin >> n;
    vvi G(n);
    vpll edge(n-1);
    rep(i,n-1) {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
        edge[i] = {a,b};
    }
    vll depth(n,-1);
    depth[0] = 0;
    vll q = {0};
    while(q.size() > 0) {
        ll at = q.back();
        q.pop_back();
        for(ll i :G[at]) if (depth[i] == -1) {
            depth[i] = depth[at] + 1;
            q.push_back(i);
        }
    }
    vll s(n);
    ll Q; cin >> Q;
    while(Q--) {
        ll t,e,x; cin >> t >> e >> x;
        ll a = edge[e-1].first;
        ll b = edge[e-1].second;
        if (depth[a] > depth[b]) {
            swap(a,b);
            t ^= 3;
        }
        if (t == 1) {
            s[0] += x;
            s[b] -= x;
        }
        else s[b] += x;
    }
    q = {0};
    while(q.size()) {
        ll at = q.back();
        q.pop_back();
        for(ll i : G[at]) if (depth[at] < depth[i]) {
            s[i] += s[at];
            q.push_back(i);
        }
    }
    for(ll i:s) cout << i << endl;
}



    // // Your code here!
    // int n; cin >> n;
    // // vvi G(n);
    // G.resize(n);
    // vi a(n-1),b(n-1);
    // rep(i,n-1) {
    //     cin >> a[i] >> b[i];
    //     a[i]--;b[i]--;
    //     // G[a[i]] = 1;
    //     // G[b[i]] = 1;
    //     G[a[i]].push_back(b[i]);
    //     G[b[i]].push_back(a[i]);
    // }
    // int q; cin >> q;
    // vll cost(n,0);
    // ll total_cost = 0;
    // vll t(q),e(q),x(q);
    // rep(i,q) {
    //     cin >> t[i] >> e[i] >> x[i];
    //     total_cost += x[i];
    // }   
    // rep(i,n) cost[i] += total_cost;

