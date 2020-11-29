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

int n;
int x[10] , y[10];
double dist(int i , int j){
    double dx = x[i-1] - x[j-1];
    double dy = y[i-1] - y[j-1];
    //cout << dx << dy << endl;
    double res =  pow(dx*dx+dy*dy,0.5);
    return res;
}

int main(void){
    // Your code here!
    cin >> n;
    rep(i,n) cin >> x[i] >> y[i];
    double sum = 0.0;
    vector<int> v(n);
    rep(i,n) v[i] = i+1;
    do {
        rep(i,n-1) sum += dist(v[i],v[i+1]);
    }while(next_permutation(v.begin(),v.end()));
    int Factorial = 1;
    for (int i = 2;i <=n;i++) Factorial *=i;
    cout << fixed << setprecision(10) << sum /Factorial << endl;
    

}
