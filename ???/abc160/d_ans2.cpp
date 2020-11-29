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
using Graph = vector<vector<ll>>;


int main(void){
    // Your code here!
    ll n,x,y;cin >> n >> x >> y;
    Graph G(n);
    x--;y--;
    rep(i,n){
        if(i !=0) G[i].push_back(i-1);
        if(i !=n-1) G[i].push_back(i+1);
    }
    G[x].push_back(y);
    // 距離ごとのカウント数を保持する配列
    vector<int> d(n,0);
    rep(i,n){
        queue<int> q;
        // その地点iからの距離を格納する配列
        vector<int> D(n,-1);
        q.push(i);
        D[i] = 0;
        while( !q.empty()){
            int v = q.front();
            q.pop();
            for(auto nv:G[v]){
                if(D[nv] != -1)continue;
                D[nv] = D[v] +1;
                if(nv>i)d[D[nv]] += 1;
                q.push(nv);
            }
        }
    }
    FOR(i,1,n-1){
        cout << d[i] << endl;
    }
}
