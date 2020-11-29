#include <bits/stdc++.h>
using namespace std;

int main(void){
    // Your code here!
    int N;
    cin >> N;
    vector<string> s(N);
    for (int i = 0;i < N ; i++) cin >> s.at(i);
    int M;
    cin >> M;
    vector<string> t(M);
    for (int i = 0;i < M ; i++) cin >> t.at(i);
    int res = 0;
    for (int i = 0;i < N ; i++) {
        int re = 0;
        for ( int j= 0;j < N ; j++){
            if (s.at(i) == s.at(j)) re++;
        }
        for ( int j= 0;j < M ; j++){
            if (s.at(i) == t.at(j)) re--;
        }
        res = max(res,re);
    }
    cout << res << endl;
}