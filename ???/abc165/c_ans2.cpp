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
vector<int> a,b,c,d;
int ans;

void dfs(vector<int> A) {
    if(A.size()==n+1){
        int now = 0;
        rep(i,q) {
            if (A[b[i]]-A[a[i]] == c[i]) now+=d[i]; 
        }
        ans = max(ans,now);
        return ;
    }

    A.push_back(A.back());
    while ( A.back() <= m) {
        dfs(A);
        A.back()++;
    }
}

int main(void){
    // Your code here!
    cin >> n >> m >> q;
    a = b = c = d = vector<int>(q);
    rep(i,q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    dfs(vector<int>(1,1) );
    cout << ans << endl;
}
