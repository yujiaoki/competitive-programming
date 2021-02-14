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
struct edge {int to,cost;};
int d[2002];

int main(void){
    // Your code here!
    int n,m; cin >> n >> m;
    vector<vector<pair<int,int>>> cost(n);
    vvi G(n);
    rep(i,m) {
        int a,b,c; cin >> a >> b >> c;
        a--;b--;
        cost[a].push_back({b,c});
        G[b].push_back(a);
    }
    rep(k,n) {
        priority_queue<P, vector<P>, greater<P>> que;
        fill(d,d+n,INF);
        d[k] = 0;
        que.push(P(0,k));

        while(!que.empty()) {
            P p = que.top(); que.pop();
            int v = p.second;
            if (d[v] < p.first) continue;
            rep(i,cost[v].size()) {
                P e = cost[v][i]; // first is to, second is cost
                if (d[e.first] > d[v] + e.second) {
                    d[e.first] = d[v] + e.second;
                    que.push({d[e.first],e.first});
                }
            }
        }
        int ans = INF;
        // 同じとこから同じとこに戻るやつ
        rep(i,cost[k].size()) {
            if (k == cost[k][i].first) {
                ans = cost[k][i].second;
            }
        }
        // 目的地の一個前のやつを洗い出し
        rep(i,G[k].size()) {
            int front = G[k][i];
            // 前のやつで目的値になってるやつだけ取り出す
            rep(j,cost[front].size()) {
                if (cost[front][j].first == k) {
                    ans = min(ans,d[front] + cost[front][j].second);
                }
            }
        }
        if (ans == INF) cout << -1 << endl;
        else cout << ans << endl;
    }
}
