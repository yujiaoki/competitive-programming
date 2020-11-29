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
    int n,q; cin >> n >> q;
    vector<int> a(n),b(n);
    vector<multiset<int>> s(200005);
    multiset<int> maxs;
    auto getMax = [&](int i) {
        if (s[i].size() == 0) return -1;
        return *s[i].rbegin();
    };
    auto addYochien = [&](int i) {
        int x = getMax(i);
        if (x == -1) return;
        maxs.insert(x);
    };
    auto delYochien = [&](int i) {
        int x = getMax(i);
        if (x == -1) return;
        maxs.erase(maxs.find(x));
    };
    auto addEnji = [&](int i,int x) {
        delYochien(i);
        s[i].insert(x);
        addYochien(i);
    };
    auto delEnji = [&](int i,int x) {
        delYochien(i);
        s[i].erase(s[i].find(x));
        addYochien(i);
    };
    rep(i,n) {
        cin >> a[i] >> b[i];
        addEnji(b[i],a[i]);
    }

    rep(i,q) {
        int c,d; 
        cin >> c >> d;
        c--;
        delEnji(b[c],a[c]);
        b[c] = d;
        addEnji(b[c],a[c]);
        int ans = *maxs.begin();
        cout << ans << endl;
    }
}
