#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
typedef long long ll;
const ll MOD=1000000007;
using namespace std;

int main(void){
    // Your code here!
    int n;
    cin >> n;
    vector<int> p(n+1);
    p.at(0) = 0;
    int count = 0;
    FOR(i,1,n) {
        cin >> p.at(i);
        if (p.at(i) >= i ) count++;
    }
    cout << count << endl;
}