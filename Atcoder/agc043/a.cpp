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

char c[505][505];
int min_cost[505][505] = {{INF}};
const vector<int> dx = {1,0};
const vector<int> dy = {0,1};
int h,w;
vector<ll> ans;

void dfs(int x,int y,int count){
    if((x<0||x>h-1)||(y<0||y>w-1)) return;
    if (x == h-1 && y == w-1) {
        ans.push_back(count);
        return ;
    }
    if (c[x+1][y] == '.') {
        dfs(x+1,y,count);
    }
    if (c[x][y+1] == '.'){
        dfs(x,y+1,count);
    }
    if (c[x+1][y] == '#' && c[x][y+1] == '#'){
        count++;
        dfs(x+1,y,count);
        dfs(x,y+1,count);
    }
}

int main(void){
    // Your code here!
    cin >> h>> w;
    rep(i,h){
        rep(j,w) cin>>c[i][j];
    }
    int count = 0;
    if (c[0][0] == '#') {
        count++;
        c[0][0] = '.';
    }
    if (c[h-1][w-1] == '#') {
        count++;
        c[h-1][w-1] = '.';
    }
    dfs(0,0,count);
    ll res = MIN(ans);
    cout << res << endl;
}
