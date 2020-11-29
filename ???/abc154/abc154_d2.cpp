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
    int n,k;
    cin >> n >> k;
    vector<double> p(n);
    rep(i,n) {
        cin >> p[i];
        p[i] = (1+p[i])/2;
    }
    
    double res = 0;
    int sum_m= 0;
    int res_ind = -1;
    for ( int i = 0; i <= n-k;i++){
        int sum_m2 =0;
        rep(j,k){
            sum_m2 += p[i+j];
        }
        
        if (sum_m < sum_m2){
            res_ind = i;
            sum_m = sum_m2;
        }
    }
 
    double res2 =0;
    rep(s,k) {
        double sum2 = p[res_ind+s]*(p[res_ind+s]+1)/2;
        res2 += (double)sum2/p[res_ind+s];
    }
    

 cout << res2 << endl;
}