#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
typedef long long ll;
const ll MOD=1000000007;
using namespace std;

int main(void){
    // Your code here!
    ll n,m;
    cin >> n >> m;
    if (m != 0) {
    vector<ll> p(m);
    vector<string> s(m);
    rep(i,m) cin >> p.at(i) >> s.at(i);
    vector<ll> collect_num(n);
    rep(i,n) collect_num.at(i) = 0; 
    ll correct = 0;
    vector<ll> penalty(n);
    rep(i,m) {
        if (s.at(i) == "AC") {
            collect_num.at(p.at(i)-1) = 1;
        }
    }
    rep(i,n) if (collect_num.at(i) ==1) correct++;
    int i =0;
    while (i <n) {
        if (collect_num.at(i) ==1){
            rep(j,m) {
                if (p.at(j) == i+1 && s.at(j) == "WA") penalty.at(i) +=1;
                if (p.at(j) == i+1 && s.at(j) == "AC") break;
            }
            }
            i++;
        }
    int penaltysum =0;
    rep(i,n) penaltysum+=penalty.at(i);
    cout << correct << ' ' << penaltysum << endl;
    }
    else cout << 0 << ' ' << 0 << endl;
}
