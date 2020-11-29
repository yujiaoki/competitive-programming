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
    ll n; cin >> n;
    string ans = "";
    ll now = 1;
    for (int i = 1; ; i++) {
        if ( n <= pow(26,i)) {
            rep(j,i) {
            //     if (j == i-1) {
            //         ans+= (char)(n%26  +'a');
            //         n/= 26;
            //         continue;
            // }
            if (n == pow(26,i)) {
                ans += 'z';
                continue;
            }
            if (j == 0){
                ans+= (char)((n+25)%26+'a');
                n/= 26;
                continue;
            }
                ans+= (char)((n)%26+'a');
                n/= 26;
            }
            break;
        }
        n -= pow(26,i);
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}
