#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
typedef long long ll;
const ll MOD=1000000007;
using namespace std;

int main(void){
    int h,n;
    cin >> h >> n;
    vector<int> a(n);
    int sum=0;
    rep(i,n) {
        cin >> a.at(i);
        sum += a.at(i);
    }
    if (h <= sum) cout << "Yes" << endl;
    else cout << "No" << endl;
}