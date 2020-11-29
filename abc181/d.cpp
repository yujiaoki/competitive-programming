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

int main(void){
    // Your code here!
    string S; cin >> S;
    if (  S == "8" || S == "16" || S == "61" || S =="24" || S =="42" || S =="32"|| S =="23"|| S =="48"|| S =="84"|| S =="56"|| S =="65"|| S =="64"|| S =="46"|| S =="72"|| S =="27" || S =="88"|| S =="96"|| S =="69") {
        cout << "Yes" << endl;
        return 0;
    }
    int n = S.size();
    vs list8;
    FOR(i,13,124) {
        int m = i*8;
        string str = to_string(m);
        if (str.size() != 3) continue;
        // bool ch = true;
        // rep(j,str.size()) {
        //     if (str[j] == '0') ch = false;
        // } 
        // if (ch) list8.push_back(str);
        list8.push_back(str);
    }
    for (auto x:list8) {
        vb used(n,false);
        bool res = true;
        rep(i,3) {
            bool now = false;
            rep(j,n) {
                if (!used[j] && S[j] == x[i] ) {
                    used[j] = true;
                    now = true;
                    break;
                }
            }
            if (!now){
                res = false;
                break;
            } 
        }
        if (res) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
