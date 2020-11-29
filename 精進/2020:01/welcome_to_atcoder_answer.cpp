#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
typedef long long ll;
const ll MOD=1000000007;
using namespace std;

int main(void){
    // Your code here!
    int N, M;
    int WA[105000];
    bool AC[105000];
    cin >> N >> M;
    int WAnum = 0;
    int ACnum = 0;
    FOR(i,1,N) {
        WA[i] = 0;
        AC[i] = false;
    }

    while (M--) {
        int p;
        string S;
        cin >> p >> S;
        if (AC[p]) continue;
        if (S =="AC") {
            AC[p] =true;
            ACnum++;
            WAnum +=WA[p];
        } else if (S =="WA") {
            WA[p]++;
        }
    }
    cout << ACnum << " " << WAnum << endl;
}
