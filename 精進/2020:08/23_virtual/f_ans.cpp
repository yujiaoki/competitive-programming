#include <bits/stdc++.h>
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
//---------------------------------------------------------------------------------------------------
typedef pair<int,int> P;

int main(void){
    // Your code here!
    int N; cin >> N;
    string S; cin >> S;
    int Q; cin >> Q;
    while(Q--) {
        int k;cin >> k;
        ll ans = 0,m = 0,c = 0,mc = 0;
        rep(i,k) {
            if (S[i] == 'M') m++;
            if (S[i] == 'C') {
                c++;
                mc += m;
            }
        }
        if (S[0] == 'D') ans += mc;

        rep(i,N-k) {
            // erase left i
            if (S[i] == 'M') {
                m--;
                mc -= c;
            }
            if (S[i] == 'C') {
                c--;
            }
            // add right i + d
            if (S[i+k] == 'M') {
                m++;
            }
            if (S[i+k] == 'C') {
                c++;
                mc += m;
            }
            if (S[i+1] == 'D') {
                ans += mc;
            }
        }

        FOR(i,N-k,N-2) {
            if (S[i] == 'M') {
                m--;
                mc -= c;
            }
            if (S[i] == 'C') {
                c--;
            }
            if (S[i+1] == 'D') {
                ans += mc;
            }
        }
        cout << ans << endl;
    }
}
