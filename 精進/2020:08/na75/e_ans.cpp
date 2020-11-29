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
const int MAX_DIGIT = 50;
ll dp[100][2];
int main(void){
    // Your code here!
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    for (int d = 0; k < MAX_DIGIT; d++) {
        ll mask = 1LL << (MAX_DIGIT - d - 1);

        int num = 0;
        rep(i,n) if (a[i] & mask) num++;

        ll cost0 = mask*num;
        ll cost1 = mask * (n-num);

        if (dp[d][1] != -1) {
            chmax(dp[d+1][1],dp[d][1]+max(cost0,cost1));
        }
        if (dp[d][0] != -1) {
            if (k & mask) chmax(dp[d+1][1],dp[d][0]+cost0);
        }
        if (dp[d][0] != -1) {
            if (k & mask) chmax(dp[d+1][0],dp[d][0]+ cost1);
            else chmax(dp[d+1][0],dp[d][0]+ cost0);
        }

    }
    cout << max(dp[MAX_DIGIT][0],dp[MAX_DIGIT][1]) << endl;
}
