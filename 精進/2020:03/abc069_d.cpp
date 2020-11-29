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
    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};
    int nd = 0;
    int h,w; cin >> h >> w;
    int n; cin >> n;
    vector<int> a(n);
    rep(k,n) {
        cin >> a[k];
        if (k!=0) a[k]+=a[k-1];
    }
    int v[105][105] = {0};
    int now =1 ,i = 0,j = 0;
    for (int cnt =0;cnt <h*w;cnt++){
        if(cnt >= a[now-1]) ++now;
        v[i][j] = now;
        if ( j+y[nd] < 0){
            i++;
            nd = 0;
            j--;
        }
        else if (j + y[nd] > w-1 ){
            i++;
            nd = 2;
            j++;
        }
        j += y[nd];
    }
    rep(i,h){
        rep(j,w){
            cout << v[i][j];
            if (j != w-1) cout << " ";
    }
    cout << endl;
    }
    }
