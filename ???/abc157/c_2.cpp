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
    int N,M; cin >> N >> M ;
    vector<int> s(M);
    vector<int> c(M,0);
    bool res = true;
    map<int,int> mp;
    rep(i,M) {
        cin >> s[i] >> c[i];
        if (mp[s[i]] !=0 ){
            if (mp[s[i]] != c[i]){
                res = false;
                break;
            }
        }
        mp[s[i]] = c[i];
        if (N>1 && s[i] ==1 && c[i] == 0){
            res = false;
            break;
        }
    }
    if (!res) cout << -1 << endl;
    else {if (N==1){
        int d = 0;
        rep(i,M){
            d = c[i];
        }
        cout << d ;
    }
        else if(N==2){
            vector<int> d = {1,0};
            rep(i,M){
                d[s[i]-1] = c[i];
            }
            rep(i,2){
            cout << d[i];
            }
        }
        else {
            vector<int> d ={1,0,0};
            rep(i,M){
                d[s[i]-1] = c[i];
            }
            rep(i,3){
            cout << d[i] ;
            }
        }
    }
}
