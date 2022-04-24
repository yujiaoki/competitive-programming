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
    ll k; cin >> k;
    string s; cin >> s;
    string t; cin >> t;
    vll taka(10,0),ao(10,0),total(10,0);
    rep(i,4) taka[s[i] - '0']++;
    rep(i,4) ao[t[i] - '0']++; 
    FOR(i,1,9) {
        total[i] = taka[i] + ao[i];
    }
    ll taka_win = 0, ao_win = 0;
    FOR(i,1,9) {
        FOR(j,1,9) {
            vll taka_now = taka, ao_now = ao;
            taka_now[i]++;
            ao_now[j]++;
            ll taka_sum = 0 ,ao_sum = 0;
            // sum の計算
            FOR(l,1,9) {
                taka_sum += l*pow(10,taka_now[l]);
                ao_sum += l*pow(10,ao_now[l]);
            }
            if (i == j ){
                if (taka_sum > ao_sum) taka_win += max((ll)0,(k - total[i])*(k-total[j]-1)/2);
                else ao_win += max((ll)0,(k - total[i])*(k-total[j]-1)/2);
            } else {
                if (taka_sum > ao_sum) taka_win += max((ll)0,(k - total[i])*(k-total[j]));
                else ao_win += max((ll)0,(k - total[i])*(k-total[j]));
            }
        }
    }
    cout << setprecision(10) << (long double)taka_win/(taka_win+ao_win)<< endl;
}
