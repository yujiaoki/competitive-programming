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
int N,X,Y;
int dx[] = {1,0,-1,1,-1,0};
int dy[] = {1,1,1,0,0,-1};
vector<vector<int>> cost(440,vector<int>(440,-1));
vector<vector<bool>> mark(440,vector<bool>(440,false));
int main(void){
    // Your code here!
     cin >> N >> X >> Y;
     X+=220;Y+=220;
    rep(i,N) {
        int x,y;cin>> x >> y;
        x += 220;
        y += 220;
        mark[x][y] = true;
    }
    int ans = 100000;
    queue<pair<int,int>> que;
    que.push(make_pair(220,220));
    cost[220][220] = 0;
    while(!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        if (mark[x][y]) continue;
        if (x == X && y == Y) {
            cout << cost[x][y] << endl;
            return 0;
        }
        rep(i,6) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(cost[nx][ny] == -1){
                que.push(make_pair(nx,ny));
                cost[nx][ny] = cost[x][y] + 1;
            }
            cost[nx][ny] = min(cost[nx][ny],cost[x][y]+1);
        }
    }
    cout << -1 << endl;
}
