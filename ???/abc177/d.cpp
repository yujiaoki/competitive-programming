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
//---------------------------------------------------------------------------------------------------
typedef pair<int,int> P;

int main(void){
    // Your code here!
    int n,m; cin >> n >> m;
    vector<vector<int>> G(n);
    set<P> st;
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        if (st.find({a,b}) != st.end() ||st.find({b,a}) != st.end() ) continue;
        G[a].push_back(b);
        G[b].push_back(a);
        st.insert({a,b});
    }
    // vector<vector<int>> score(n,vector<int>(n,-1));
    // rep(i,n) score[i][i] = 0;
    ll ma = 1;
    rep(i,n) {
        ll now = 0;
        if (G[i].empty()) continue;
        rep(j,G[i].size()) now++;
        if (now+1 > ma) ma = now+1;
    }
    cout << ma<< endl;
}
