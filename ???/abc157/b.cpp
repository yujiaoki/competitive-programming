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
    vector<vector<int>> A(3,vector<int>(3));
    rep(i,3){
        rep(j,3){
            cin >> A[i][j];
        }
    }
    int n; cin >> n;
    vector<int> b(n);
    rep(i,n) cin >> b[i];
    int a[3][3];
    rep(i,n){
        rep(j,3){
            rep(k,3){
                if (A[j][k] == b[i]) a[j][k] = 1;
            }
        }
    }
    bool res = false;
    rep(i,3){
        if (a[i][0] == 1 && a[i][1] == 1 && a[i][2] == 1 ){
            res = true;
        }
    }
    if (a[0][0] == 1 && a[1][0] == 1 && a[2][0] == 1 ){
            res = true;
        }
    if (a[0][1] == 1 && a[1][1] == 1 && a[2][1] == 1 ){
            res = true;
        }
    if (a[0][2] == 1 && a[1][2] == 1 && a[2][2] == 1 ){
            res = true;
        }
    if (a[0][0] == 1 && a[1][1] == 1 && a[1][1] == 1 ){
            res = true;
        }
    if (a[2][0] == 1 && a[1][1] == 1 && a[0][2] == 1 ){
            res = true;
        }
    
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
}
