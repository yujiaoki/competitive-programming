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
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
int main(void){
    // Your code here!
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    int ans = 0;
    rep(i,h) cin >> s[i];
    rep(si,h) {
        rep(sj,w) {
        if(s[si][sj] == '#') continue;
        vector<vector<int>> dist(h,vector<int>(w,INF));
        queue<pair<int,int>> q;
        if (dist[si][sj] !=INF) continue;
        dist[si][sj] = 0;
        q.push(make_pair(si,sj));
        auto update = [&](int i ,int j, int x){
            if (dist[i][j] != INF) return;
            dist[i][j] = x;
            q.push(make_pair(i,j));
        };
        update(si,sj,0);
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            rep(dir,4) {
                int ni = i+di[dir],nj = nj = j + dj[dir];
                if ( ni<0 || ni>=h||nj<0||nj>=w)continue;
                if (s[ni][nj] == '#') continue;
                update(ni,nj,dist[i][j]+1);
            }
        }
        rep(i,h){
            rep(j,w) {
            if (dist[i][j] == INF)continue;
            ans = max(ans,dist[i][j]);
        }
        }
    }
    }
    cout << ans << endl;
}