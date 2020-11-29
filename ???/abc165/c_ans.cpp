#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
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


int n,m,q;
vector<ll> a,b,c,d;

ll calc(const vector<int> &A){
    ll res = 0;
    rep(i,q) {
        if(A[b[i]]-A[a[i]] == c[i]) res += d[i];
    }
    return res;
}

void dfs(vector<int> &A,ll &res) {
    if(A.size()==n+1){
        ll tmp = calc(A);
        chmax(res,tmp);
        return;
    }
    ll ba = A.back();
    for(int add = ba;add <= m;add++) {
        A.push_back(add);
        dfs(A,res);
        A.pop_back();
    }
}

ll solve() {
    ll res = 0;
    vector<int> A({1});
    dfs(A,res);
    return res ;
}
int main(void){
    // Your code here!
    while(cin >> n >> m >> q){
        a.resize(q);b.resize(q);c.resize(q);d.resize(q);
        rep(i,q) cin >> a[i] >> b[i] >> c[i] >> d[i];
        cout << solve() << endl;
    }
}
