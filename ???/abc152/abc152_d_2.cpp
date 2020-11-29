#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
typedef long long ll;
const ll MOD=1000000007;
using namespace std;
typedef pair<int,int> P;

P f(int x) {
    int a = x % 10;
    int b = 0;
    while (x) {
        b = x;
        x /= 10;
    }
    return P(a,b);
}
int main(void){
    // Your code here!
    int n;
    cin >> n;
    map<P,int> freq;
    FOR(i,1,n) {
        P p = f(i);
        freq[p]++;
    }
    ll ans = 0;
    FOR(i,1,n) {
        P p = f(i);
        P q(p.second,p.first);
        ans += freq[q];
    }
    cout << ans << endl;
}