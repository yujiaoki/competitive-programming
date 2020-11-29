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
    int result = n;
    bool judge2 =true;
    while (judge2) {
        bool judge = true;
        FOR(i,1,result-1) {
            if (x.at(i) > x.at(i+1)) {
                if (x.at(i)-l.at(i) < x.at(i+1)+l.at(i+1)) {
                    judge = false;
                    x.erase(x.begin()+i+1);
                    l.erase(l.begin()+i+1);
                    result--;
                    break;
                }
        }
            else {
                if (x.at(i) + l.at(i) > x.at(i+1)-l.at(i+1)) {
                    judge = false;
                    if (l.at(i) >= l.at(i+1)) {
                        x.erase(x.begin()+i);
                        l.erase(l.begin()+i);
                        result--;
                        break;
                    } 
                }
        }
        }
        if (judge) {
            judge2 =false;
            cout << result << endl;
        }
    }   
}