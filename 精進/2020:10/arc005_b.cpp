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

int main(void){
    // Your code here!
    vector<int> DX = {0, 1, 0, -1, 1, 1, -1, -1};
     vector<int> DY = {-1, 0, 1, 0, -1, 1, 1, -1};
  
     int x, y;
     string W;
     cin >> x >> y >> W;
     x--, y--;
  
     vector<string> S(9);
     for (int i = 0; i < 9; i++) {
         cin >> S[i];
     }
  
     int D = 0;
     if (W == "U") D = 0;
     if (W == "R") D = 1;
     if (W == "D") D = 2;
     if (W == "L") D = 3;
     if (W == "RU") D = 4;
     if (W == "RD") D = 5;
     if (W == "LD") D = 6;
     if (W == "LU") D = 7;
  
     string ans = "";
     for (int i = 0; i < 4; i++) {
         ans += S[y][x];
         int toY = y + DY[D];
         int toX = x + DX[D];
         if (toY < 0 || toY >= 9) DY[D] = -DY[D];
         if (toX < 0 || toX >= 9) DX[D] = -DX[D];
         y += DY[D];
         x += DX[D];
}
cout << ans << endl;
}
