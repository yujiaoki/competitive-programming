#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
typedef long long ll;
const ll MOD=1000000007;
using namespace std;

int main(void){
    // Your code here!
    int w,h,n;
    cin >> w >> h >> n;
    if (w >= h) cout << ceil((double)n / w) << endl;
    else cout << ceil((double)n / h) << endl;
}