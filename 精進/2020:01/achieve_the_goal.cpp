#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
typedef long long ll;
const ll MOD=1000000007;
using namespace std;

int main(void){
    // Your code here!
    int n,k,m;
    cin >> n >> k >> m;
    vector<int> a(n-1);
    rep(i,n-1) cin >> a.at(i);
    int sumtest =0;
    rep(i,n-1) sumtest+=a.at(i);
    int target =0;
    target =m*n-sumtest;
    if (target <= k && target >= 0) cout << target << endl;
    else if (target < 0) cout << 0 << endl;
    else cout << -1 << endl;

    
}