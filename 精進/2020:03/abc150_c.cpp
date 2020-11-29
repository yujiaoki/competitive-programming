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
    int n; cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];
    vector<int> v(n);
    rep(i,n) v[i] = i+1;
    int a,b;
    int counter =  1;
    do{
        bool a_j = true;
        bool b_j = true;
        rep(i,n){
            if (v[i] != p[i]) {
                a_j = false;
            }
            if (v[i] != q[i]) {
                b_j = false;
            } 
        }
        if (a_j) a = counter;
        if (b_j) b = counter;
        counter++;
    }while(next_permutation(v.begin(),v.end()));
    cout << abs(a-b) << endl;
}
