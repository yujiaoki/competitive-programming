#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
typedef long long ll;
const ll MOD=1000000007;
using namespace std;
const long double PI = (acos(-1));
const long double EPS = 0.000000001;

long double a,b,x ;

void input() {
    cin >> a >> b >> x;
}

long double f(long double , long double b, long double theta) {
    if (theta > PI/2.0-EPS){
        return 0.0;
    }
    long double ret;
    if (a * tan(theta) <= b) {
        ret = a*a*b-a*a*a*tan(theta) /2.0;
    } else {
        ret = b*b / tan(theta) * a/2.0;
    }
    return ret;
}
void solve() {
    input();
    long double ok = PI / 2.0;
    long double ng = 0.0;
    for (int _= 1; _ <= 10000; _++){
        long double mid = (ok + ng) /2.0;
        if (f(a,b,mid) < x) ok = mid ;
        else ng = mid ;
    }
    cout << fixed << setprecision(10) << ok / PI *180 << endl;
    return;
}
int main(void){
    // Your code here!
    solve();
    return 0;
}