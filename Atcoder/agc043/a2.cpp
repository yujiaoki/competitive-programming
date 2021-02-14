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


const vector<int> dx = {1,0};
const vector<int> dy = {0,1};




int main(void){
    // Your code here!
    int h,w;cin >> h>> w;
    vector<vector<char>> c(h,vector<char>(w));
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
    int min_cost[505][505] ;
    rep(i,505)rep(j,505) min_cost[i][j] = INF;
    // vector<vector<int>> min_cost(h,vector<int>(w,INF));
    queue<pair<int,int>> que;
    que.emplace(0,0);
    min_cost[0][0] = 0;
    while(!que.empty()){
        auto p = que.front();
        que.pop();
        for (int i = 0; i < 2;i++){
            int nx = p.first + dx[i],ny = p.second + dy[i];
            if((nx<0||nx>h-1)||(ny<0||ny>w-1)) continue;
            if (c[nx][ny] == '.') {
                if (min_cost[nx][ny] >  min_cost[p.first][p.second]){
                    min_cost[nx][ny] =  min_cost[p.first][p.second];
                    que.emplace(nx,ny);
                }
            }
        }
        
        if (c[p.first + dx[0]][p.second + dy[0]] == '#' && c[p.first + dx[1]][p.second + dy[1]] == '#'){
                
                if (min_cost[p.first + dx[0]][p.second + dy[0]] >  min_cost[p.first][p.second]+1){
                    if((p.first + dx[0]<0||p.first + dx[0]>h-1)||(p.second + dy[0]<0||p.second + dy[0]>w-1)) continue;
                    min_cost[p.first + dx[0]][p.second + dy[0]] =  min_cost[p.first][p.second]+1;
                    que.emplace(p.first + dx[0],p.second + dy[0]);
                }
        }
        if (c[p.first + dx[0]][p.second + dy[0]] == '#' && c[p.first + dx[1]][p.second + dy[1]] == '#'){
            if (min_cost[p.first + dx[1]][p.second + dy[1]] >  min_cost[p.first][p.second]+1){
                    if((p.first + dx[1]<0||p.first + dx[1]>h-1)||(p.second + dy[1]<0||p.second + dy[1]>w-1)) continue;
                    min_cost[p.first + dx[1]][p.second + dy[1]] =  min_cost[p.first][p.second]+1;
                    que.emplace(p.first + dx[1],p.second + dy[1]);
                }
        }
    }
    
    cout << min_cost[h-1][w-1] + count << endl;
}
