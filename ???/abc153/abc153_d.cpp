#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
typedef long long ll;
const ll MOD=1000000007;
using namespace std;

int main(void){
    ll h;
    cin >> h;
    vector<ll> a((ll)log2(h)+1);
    a.at(0) = h;
    ll count = 0;
    while(true) {
        if(a.size() > 1 && a.at(0) ==1) {
            count++;
            a.erase(a.begin());
    }
        else if (a.at(0) > 1){
            count ++;
            a.push_back(floor((double)a.at(0)/2));
            a.push_back(floor((double)a.at(0)/2));
            a.erase(a.begin());
        }
        else if (a.size() == 1 && a.at(0) == 1) {
            count++ ;
            cout << count << endl;
            break;
        } 
    }
}
