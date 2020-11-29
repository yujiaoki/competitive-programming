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
    int n;cin >> n;
    int c_f ,c_b;
    cin >> c_f >> c_b;
    string s; cin >> s;

    vector<int> mark(n);
    rep(i,n-1) mark[i] =0;
    mark[n-1] = -1;
    vector<bool> canmove(n);
    rep(i,n) {
        if(s[i] == 's'){
            canmove[i] = true;
        }
        else canmove[i] =false;
    }
    
    int pos = n-1;
    int cost = 0;
    while (){
        rep(i,n){
            vector<string> r;
            if (i !=pos and canmove[i] ==true;){
                mark[i] = 1;
                if (i < pos){
                    cost += c_b;
                    canmove[i] = false;
                    rep(j,n) {
                        if (j > i and canmove[j] ==true;) canmove[j]=false;
                    }
                }
                else {
                    cost += c_f;
                    canmove[i] = false;
                    rep(j,n) {
                        if (j > i and canmove[j] ==true;) canmove[j]=false;
                    }
                }
            }
                
            }
        }
    }

    




}