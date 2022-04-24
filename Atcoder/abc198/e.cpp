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
    vi c(n);
    rep(i,n) cin >> c[i];
    vvi G(n);
    rep(i,n-1) {
        int a,b; cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    priority_queue<tuple<ll, ll, set<int>>,vector<tuple<ll, ll, set<int>>>, greater<tuple<ll, ll, set<int>>>> que;
    vll d(n,1e11);
    d[0] = 0;
    set<int> st;
    st.insert(c[0]);
    vi res;
    res.push_back(1);
    que.push({0,0,st}); // first はコスト、secondは始点
    while(!que.empty()) {
        tuple<ll, ll, set<int>> p = que.top(); 
        que.pop();
        ll v = get<1>(p);
        set<int> st_now = get<2>(p);
        if (d[v] < get<0>(p)) {
            continue;
        }
        rep(i,G[v].size()) {
            set<int> st_m = st_now;
            int to = G[v][i];
            if (d[to] > d[v] + 1) {
                if (st_m.find(c[to]) == st_m.end()) {
                    res.push_back(to + 1);
                    st_m.insert(c[to]);
                }
                d[to] = d[v] + 1;
                que.push({d[to],to,st_m});
            }
        }
    }
    Sort(res);
    rep(i,res.size()) {
        cout << res[i] << endl;
    }

}
