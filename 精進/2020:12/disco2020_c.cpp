#include <bits/stdc++.h>
// #include<atcoder/all>
// using namespace atcoder;
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
int h,w,k;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

char s[500][500];
int ans[500][500] = {0};

// void dfs(int x,int y,int num) {
//     if (x < 0 || x >= h || y < 0 || y >= w) return;
//     ans[x][y] = num;
//     rep(i,4) {
//         int nx = x + dx[i];
//         int ny = y + dy[i];
//         if ((s[nx][ny] == '#') || ans[nx][ny] != 0) continue;
//         dfs(nx,ny,num);
//     }
// }

int main(void){
    // Your code here!
    cin >> h >> w >> k;
    rep(i,h) rep(j,w) cin >> s[i][j];
    int count = 1;
    rep(i,h)rep(j,w) {
        if (s[i][j] == '#') {
            int k = i;
            ans[i][j] = count;
            while(k - 1 >= 0 && ans[k-1][j] == 0 && s[k-1][j] != '#') {
                ans[k-1][j] = count;
                k--;
            }
            // dfs(i,j,count);
            count++;
        }
    }
    count = 1;
    rep(i,h)rep(j,w) {
        if (s[i][j] == '#') {
            int k = i;
            ans[i][j] = count;
            while(k + 1 <= h-1 && ans[k+1][j] == 0 && s[k+1][j] != '#') {
                ans[k+1][j] = count;
                k++;
            }
            count++;
        }
    }
    rep(i,h)rep(j,w) {
        if (ans[i][j] != 0) {
            int k = j;
            int now = ans[i][j];
            while(k - 1 >= 0 && ans[i][k-1] == 0 ) {
                ans[i][k-1] = now;
                k--;
            }
        }
    }
    rep(i,h)rep(j,w) {
        if (ans[i][j] != 0) {
            int k = j;
            int now = ans[i][j];
            while(k + 1 <= w -1  && ans[i][k+1] == 0 ) {
                ans[i][k+1] = now;
                k++;
            }
        }
    }
    rep(i,h){
        rep(j,w) {
            cout << ans[i][j] << " ";
        }
        cout  << endl;
    }
}
