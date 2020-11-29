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
    vector<int> m(1000);
    x.at(0) = 0;
    l.at(0) = 0;
    FOR(i,1,n) {
        cin >>x.at(i) >> l.at(i);
        if (x.at(i)-l.at(i)+1>0) {
            FOR(j,x.at(i)-l.at(i)+1,x.at(i)+l.at(i)-1) {
                m.at(j)++;
            }
        }
        else {
            FOR(j,1,x.at(i)+l.at(i)-1) {
                m.at(j)++;
            }
        }
    }
    int maxElement = *std::max_element(m.begin(), m.end());
    cout << n-maxElement+1 << endl;
}