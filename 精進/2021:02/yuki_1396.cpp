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
const ll MOD=998244353;
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
ll prime_factorize(ll n) {
    ll res = 1;
    for (ll p = 2;p*p <= n;++p) {
        if (n%p!=0) continue;
        ll num = 0;
        while(n%p ==0) {
            ++num;
            n/=p;
        }
        res+= num;
    }
    if (n!=1) res++;
    return res;
}
bool isPrime(int x){
    int i;
    if(x < 2)return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
    return 1;
}

int main(void){
    // Your code here!
    ll n; cin >> n;
    if (n== 2) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 3) {
        cout << 2 << endl;
        return 0;
    }
    if (n == 4) {
        cout << 4 << endl;
        return 0;
    }
    // FOR(i,1,n) {
    //     if (prime_factorize(i) >= n-1) {
    //         cout << i << endl;
    //         return 0;
    //     }
    // }
    vi prime_vector;
    FOR(i,2,100000) {
        if (isPrime(i)) prime_vector.push_back(i);
    }
    ll ans = 1;
    ll count = 1;
    for(auto x:prime_vector) {
        if (count >= n - 1) {
            cout << ans << endl;
            break;
        }
        count*=2;
        ans *= x;
        ans %= MOD;
    }
}
