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
    vector<pair<int,int>  > P;
    FOR(i,1,n) {
        int a,b;
        cin >>  a >> b;
        P.push_back(make_pair(a+b,a-b));
    }
    sort(P.begin(),P.end());
    int count = 1;
    int index = 0;
    for (int i = 1;i < n;i++) {
        if ( P.at(index).first <= P.at(i).second){
            count++;
            index =i;
        }
    }
    cout << count << endl;
}