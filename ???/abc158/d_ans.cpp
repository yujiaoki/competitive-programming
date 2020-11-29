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
    string s; cin >> s;
    int q; cin >> q;
    deque<char> deq;
    rep(i,s.size()) deq.push_back(s[i]);
    bool isReverse = false;
    rep(i,q){
        int t;cin >> t;
        if (t == 1){
            isReverse = !isReverse;
            // cout << s << endl;
        }
        else if (t == 2){
            int f;cin >> f;
            char c;cin >>c;
            if (f == 1){
                  if (!isReverse){
                      deq.push_front(c);
                  }else{
                      deq.push_back(c);
                  }
                
                // cout << s << endl;
            }
            else  {
                if (!isReverse){
                      deq.push_back(c);
                  }else{
                      deq.push_front(c);
                  }
                // cout << s << endl;
            }
        }
    }
    if (isReverse) reverse(deq.begin(),deq.end());
        rep(i,deq.size()){
            cout << deq[i];
        }
}
