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



int main(void){
    // Your code here!
    int n,M ;
    cin >> n >> M ;
    vector<int> a(n+1,0);
    vector<int> b(n+1,0);
    FOR(i,1,n) cin >> a.at(i) >> b.at(i) ;
    vector<vector<int>> q(100005);
    FOR(i,i,n) q.at(a.at(i)).push_back(b.at(i));

    priority_queue<int> que;
    int ans = 0;
    FOR(m,1,M) {
        for (auto &x:q.at(m)){
            que.push(x);
        };
        if (!que.empty()) {
            ans += que.top();
            que.pop();
        }
    }
    cout << ans << endl;
}