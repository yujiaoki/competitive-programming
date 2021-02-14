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
// double ans = 0;
// double A,B,C;
// void dfs (double a,double b,double c, double now,double count) {
//     if (a == 100 || b == 100 || c == 100) {
//         ans += now*count;
//         return;
//     }
//     count++;
//     if (a > 0) dfs(a+1,b,c,now*a/(a+b+c),count);
//     if (b > 0)dfs(a,b+1,c,now*b/(a+b+c),count);
//     if (c > 0)dfs(a,b,c+1,now*c/(a+b+c),count);
// }
double dp[101][101][101];//確率
double dp2[101][101][101];//回数
int main(void){
    // Your code here!
    int A,B,C;cin >> A >> B >> C;
    dp[A][B][C] = 1;
    // dp[0][B][C] = 0;
    // dp[A][0][C] = 0;
    // dp[A][B][0] = 0;
    dp2[A][B][C] = 0;
    FOR(a,A,99) FOR(b,B,99) FOR(c,C,99) {
        dp[a+1][b][c] += dp[a][b][c]*a/(a+b+c);
        dp[a][b+1][c] += dp[a][b][c]*b/(a+b+c);
        dp[a][b][c+1] += dp[a][b][c]*c/(a+b+c);
        dp2[a+1][b][c]++;
        dp2[a][b+1][c]++;
        dp2[a][b][c+1]++;
    }
    double ans = 0;
    FOR(b,B,99) FOR(c,C,99) {
        ans += dp[100][b][c]*(100-A+b-B+c-C);
    }
    FOR(c,C,99) FOR(a,A,99) {
        ans += dp[a][100][c]*(a-A+100-B+c-C);
    }
    FOR(a,A,99) FOR(b,B,99) {
        ans += dp[a][b][100]*(a-A+b-B+100-C);
    }
    cout << setprecision(10) << ans << endl;
}

