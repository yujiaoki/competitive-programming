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


vs trim(vs X) {
    int n = X.size();
    int min_r = 5000;
    int max_r = 0;
    int min_c = 5000;
    int max_c = 0;
    rep(i,n) {
        rep(j,n) {
            if (X[i][j] == '#') {
                min_r = min(min_r , i);
                max_r = max(max_r,i);
                min_c = min(min_c, j);
                max_c = max(max_c,j);
            }
        }
    }
    vs trimed_X;
    FOR(i,min_r,max_r) {
        trimed_X.push_back(X[i].substr(min_c, max_c - min_c + 1));
    }
    return trimed_X;
}

vs rotate(vs X) {
    int H = X.size();
    int W = X[0].size();

    vs x(W);
    rep(i,W) {
        for (int j = H - 1; j >= 0; j--) {
            x[i].push_back(X[j][i]);
        }
    }
    return x;
}

bool checker (vs s, vs t) {
    if (s.size() == t.size() && s[0].size() == t[0].size())
  {
    bool ok = true;
    rep(i,s.size()) {
        rep(j,s[0].size()) {
            if (s[i][j] != t[i][j]) ok = false;
        }
    }
    return ok;
  } else {
      return false;
  }
}

int main(void){
    // Your code here!
     int n; cin >> n;
     if (n == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    vs S(n);
    vs T(n);
    
    for (auto& s :S) {
        cin >> s;
    }
    for (auto& t:T) {
        cin >> t;
    }
    
    auto s = trim(S);
    auto t = trim(T);
    bool ok = false;
    if ((s.size() == t.size() && s.at(0).size() == t.at(0).size())
      || (s.size() == t.at(0).size() && s.at(0).size() == t.size())) {
            rep(_,4) {
                t = rotate(t);
                if (checker(s,t)) ok = true;
            }
      }
    
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}