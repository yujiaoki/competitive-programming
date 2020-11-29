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
int n,m,x;
int dfs(int &count){
    
}

int main(void){
    // Your code here!
    cin >> n >> m >> x;
    vector<int> c(n);
    map<int,vector<vector<int>>,greater<int> > mp;
    rep(i,n){
        int c ; cin >> c;
        vector<int> a(m);
        rep(j,m) cin >> a[j];
        mp[c].push_back(a);
    }
    int count = 0;
    vector<int> ans(m,0);
    for(auto y:mp){
        count+=y.first;
        rep(i,y.second.size()){
        rep(j,m){
            ans[j] += y.second[i][j];
        }
        }
    }
    if(MIN(ans)< x) {
        cout << -1 << endl;
        return 0;
    }
    for(auto y:mp){
        rep(i,y.second.size()){
        rep(j,m){
            ans[j] -= y.second[i][j];
        }
        if(MIN(ans)>=x){
            count-=y.first;
            continue;
        }
        else {
            rep(j,m){
                ans[j] += y.second[i][j];
            }
        }
        }
    }
    cout << count << endl;
}
