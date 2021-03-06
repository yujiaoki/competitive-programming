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
    ll n,m,k; cin >> n >> m >> k;
    queue<ll> a,b;
    rep(i,n) {
        ll A; cin >> A ;
        a.push(A);
    }
    rep(i,m) {
        ll B; cin >> B ;
        b.push(B);
    }
    ll ans = 0;
    ll time = 0;
    while(time <= k) {
        if(!a.empty()&&!b.empty()) {
            if (a.front() > b.front()) {
                if (time + b.front() <=k) {
                    ans++;
                    time+= b.front();
                    b.pop();
                } else {
                    break;
                } 
            } else {
                if (time + a.front() <=k) {
                    ans++;
                    time+= a.front();
                    a.pop();
                } else {
                    break;
                } 
            }
        } else if(a.empty() && !b.empty()) {
            if (time + b.front() <=k) {
                ans++;
                time+= b.front();
                b.pop();
            } else {
                break;
            } 
        } else if(b.empty() && !a.empty()) {
            if (time + a.front() <=k) {
                ans++;
                time+= a.front();
                a.pop();
            } else {
                break;
            } 
        } else {
            break;
        }

        if(time > k) break;
    }
    cout << ans << endl;
}
