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
typedef vector<pair<ll, ll>> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
typedef vector<vll> vvll;
typedef map<int, int> mii;
typedef set<int> si;
//---------------------------------------------------------------------------------------------------
struct edge {ll to;ll time;ll bai;};
vector<vector<edge>> G;
int main(void){
    // Your code here!
    ll n,m,x,y; cin >> n >> m >> x  >> y;
    x--;y--;
    G.resize(n);
    rep(i,m) {
        ll a,b,t,k; cin >> a >> b >> t >> k; a--;b--;
        edge s = {b,t,k}, l = {a,t,k};
        G[a].push_back(s);
        G[b].push_back(l);
    }
    priority_queue<P , vector<P> , greater<P>> que;
    vll d(n,1e17);
    d[x] = 0;
    que.push({0,x});

    while(!que.empty()) {
        P p = que.top(); que.pop();
        ll v = p.second;
        if (d[v] < p.first) continue;
        rep(i, G[v].size()) {
            edge e = G[v][i];
            if (d[v] % e.bai == 0) {
                 if (d[e.to] > d[v] + e.time) {
                    d[e.to] = d[v] + e.time;
                    que.push({d[e.to],e.to});
                 }
            } else {
                if (d[e.to] > d[v] + e.bai - d[v] % e.bai + e.time) {
                    d[e.to] = d[v] + e.bai - d[v] % e.bai + e.time;
                    que.push({d[e.to],e.to});
                }
            }
        }
    }
    if (d[y] == 1e17) cout << -1 << endl;
    else cout << d[y] << endl;
}
