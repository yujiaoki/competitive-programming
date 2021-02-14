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
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};
int main(void){
    // Your code here!
    int H,W; cin >> H >> W;
    vvc board(H,vc(W));
    rep(i,H) rep(j,W) cin >> board[i][j];
    vector<vector<P>> tere(26);
    int sx,sy,gx,gy;
    rep(i,H) rep(j,W) {
        if (board[i][j] == 'S') {
            sx = i;
            sy = j;
        }
        if (board[i][j] == 'G') {
            gx = i;
            gy = j;
        }
        if (board[i][j] != '#' && board[i][j] != '.' ) {
            tere[board[i][j]-'a'].push_back({i,j});
        }
    }
    vvi dis(H,vi(W,INF));
    dis[sx][sy] = 0;
    queue<P> que;
    que.push({sx,sy});
    while(!que.empty()) {
        P now = que.front();
        que.pop();
        int x = now.first;
        int y = now.second;
        if (board[now.first][now.second] != '.' && board[now.first][now.second] != '#' && board[now.first][now.second] != 'S' && board[now.first][now.second] != 'G') {
            if (dis[tere[board[x][y]-'a'][0].first][tere[board[x][y]-'a'][0].second] > dis[tere[board[x][y]-'a'][1].first][tere[board[x][y]-'a'][1].second] + 1) {
                dis[tere[board[x][y]-'a'][0].first][tere[board[x][y]-'a'][0].second] = dis[tere[board[x][y]-'a'][1].first][tere[board[x][y]-'a'][1].second] + 1;
                que.push({tere[board[x][y]-'a'][0]});
            }
            if (dis[tere[board[x][y]-'a'][1].first][tere[board[x][y]-'a'][1].second] > dis[tere[board[x][y]-'a'][0].first][tere[board[x][y]-'a'][0].second] + 1) {
                dis[tere[board[x][y]-'a'][1].first][tere[board[x][y]-'a'][1].second] = dis[tere[board[x][y]-'a'][0].first][tere[board[x][y]-'a'][0].second] + 1;
                que.push({tere[board[x][y]-'a'][1]});
            }
        }
        rep(i,4) {
            int nx= now.first + dx[i];
            int ny= now.second + dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            else if (board[nx][ny] == '#') continue;
            else  {
                if(dis[nx][ny] > dis[now.first][now.second]+1) {
                    dis[nx][ny] = dis[now.first][now.second]+1;
                    que.push({nx,ny});
                }
            // } else {
            //     if (dis[tere[board[nx][ny]-'a'][0].first][tere[board[nx][ny]-'a'][0].second] < dis[tere[board[nx][ny]-'a'][0].first][tere[board[nx][ny]-'a'][0].second]+1) {
            //         dis[tere[board[nx][ny]-'a'][0].first][tere[board[nx][ny]-'a'][0].second] = min(dis[tere[board[nx][ny]-'a'][0].first][tere[board[nx][ny]-'a'][0].second], dis[tere[board[nx][ny]-'a'][0].first][tere[board[nx][ny]-'a'][0].second]+1);
            //         que.push(tere[board[nx][ny]-'a'][0]);
            //     }
            //     if (dis[tere[board[nx][ny]-'a'][1].first][tere[board[nx][ny]-'a'][1].second] < dis[tere[board[nx][ny]-'a'][1].first][tere[board[nx][ny]-'a'][1].second]+1) {
            //         dis[tere[board[nx][ny]-'a'][1].first][tere[board[nx][ny]-'a'][1].second] = min(dis[tere[board[nx][ny]-'a'][1].first][tere[board[nx][ny]-'a'][1].second], dis[tere[board[nx][ny]-'a'][1].first][tere[board[nx][ny]-'a'][1].second]+1);
            //         que.push(tere[board[nx][ny]-'a'][1]);
            //     }
            }
        }
    }
    cout << dis[gx][gy] << endl;
}
