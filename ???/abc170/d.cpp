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
// map<ll,ll> prime_factor(ll n) {
//     map<ll,ll> res;
//     for(ll i = 2,i*i<=n;i++){
//         while(n%i==0) {
//             ++res[i];
//             n/=i;
//         }
//     }

//     if (n!=1) {
//         res[n] = 1;
//     }
//     return res;
// }

int main(void){
    // Your code here!
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int count = 0;
    map<ll,ll> ans;
    sort(a.begin(),a.end());
    bool res = false;
    int f = a[0];
    rep(i,n) {
        if(f!=a[i]) res = true;
    }
    if(!res) {
        cout << 0 << endl;
        return 0;
    }
    rep(i,n) {
        int cur = a[i];
        map<ll ,ll> mp;
        bool check = false;
        for (ll j = 2; j*j<=cur;j++) {
            while(cur%j==0){
                    mp[j]++;
                    cur/=j;
            }
            
            if (mp[j]!= 0 && ans[j] == 0) ans[j] = a[i];
            else if(ans[j] <= mp[j]) {
                if(check) continue;
                count++;
                check = true;
                break;
            }

        }
        if (cur!=0) {
                continue;
            } 
        if (mp[cur]!=0 && ans[cur] == 0) ans[cur] = a[i];
        else if(ans[cur] <= mp[cur]) {
            if(check) continue;
            
            count++;
            check = true;
        }
    }
    cout << n - count << endl;
}
