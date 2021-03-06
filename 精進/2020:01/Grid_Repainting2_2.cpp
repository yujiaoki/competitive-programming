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
    int h,w;
    cin >> h >> w;
    vector<vector<char>> s(h,vector<char>(w));
    rep(i,h) {
        rep(j,w) {
        cin >> s.at(i).at(j);
        }
    }
    bool can = true;
    const vector<int> dx = {1,0,-1,0};
    const vector<int> dy = {0,1,0,-1};
    rep(i,h) {
        rep(j,w) {
            if (s.at(i).at(j) == '.') continue;
            else {
                bool sharp = false;
                rep(d,4) {
                    int ni = i + dy[d];
                    int nj = j + dx[d];
                    if ( ni < 0 or ni >= h) continue;
                    if ( nj < 0 or nj >= w) continue;
                    if (s[ni][nj] == '#') {
                        sharp = true;
                    }
                }
                if (sharp == false) can = false;
                }
            }
        }
    
   
    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;
}
