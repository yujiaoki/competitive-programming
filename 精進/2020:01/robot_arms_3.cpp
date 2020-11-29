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
    vector<int> x(n+1);
    vector<int> l(n+1);
    x.at(0) = 0;
    l.at(0) = 0;
    FOR(i,1,n) cin >>x.at(i) >> l.at(i);
    int count = 0;
    FOR(i,1,n) {
        FOR(j,i+1,n) {
            if (x.at(i) > x.at(j)) {
                if (x.at(i)-l.at(i) < x.at(j)+l.at(j)) {
                    count++;
                }
        }
            else {
                if (x.at(i) + l.at(i) > x.at(j)-l.at(j)) {
                    count++;
                }
        }
    }
            cout << n-count << endl;
}
}