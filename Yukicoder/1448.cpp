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
typedef pair<ll,ll> P;
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
using A = array<ll,3>;
struct edge{
    int to;
    ll cost;
};
vector<edge> G[105];
ll dist[105][1005],T[105];

int main(void){
    // Your code here!
    int N,M; cin >> N >> M;
    rep(i,M) {
        int A,B,C; cin >> A >> B >> C;
        G[A-1].push_back({B-1,C});
        G[B-1].push_back({A-1,C});
    }
    rep(i,N) cin >> T[i];
    priority_queue<A,vector<A>,greater<A>>PQ; PQ.push({0,0,0});
    fill(dist[0],dist[N],INF); dist[0][0]=0;
    while(!PQ.empty()) {
        auto[c,v,p] = PQ.top();PQ.pop();
        if (dist[v][p] < c) continue;
        c += T[v];p = min(p+T[v],1001ll);
        for (edge e :G[v]) {
            if(chmin(dist[e.to][p],c+e.cost/p)) PQ.push({c+e.cost/p,e.to,p});
        }
    }
    ll ans=INF;
    for(int i=0;i<=1001;i++) chmin(ans,dist[N-1][i]);
    cout<<ans<<endl;
    // Your code here!

    // int n,m; cin >> n >> m;
    // vll a(m),b(m),c(m);
    // rep(i,m) {
    //     cin >> a[i] >> b[i] >> c[i];
    //     a[i]--;
    //     b[i]--;
    // }
    // vll t(n);
    // rep(i,n) cin >> t[i];
    // vector<vector<P>> Graph(n);
    // rep(i,m) {
    //     Graph[a[i]].push_back({b[i],c[i]});
    //     Graph[b[i]].push_back({a[i],c[i]});
    // }
    // priority_queue<P,vector<P>, greater<P>> que;
    // vll d(n,INF);
    // d[0] = 0;
    // que.push({0,0}); // first はcost、second はnode
    // while(!que.empty()) {
    //     P p = que.top(); 
    //     que.pop();
    //     int v = p.second;
    //     if (d[v] < p.first) continue;
    //     rep(i,Graph[v].size()) {
    //         P e = Graph[v][i];
    //         if (d[e.first] > d[v] + t[v] + e.second/(p.first+t[v])) {
    //             d[e.first] = d[v] + t[v] + e.second/(p.first+t[v]);
    //             que.push({e.first,d[e.first]});
    //         }
    //     }
    // }
    // cout << d[n-1] << endl;
}
