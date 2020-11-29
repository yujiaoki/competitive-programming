#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int n,m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    vector<int> res(m+1);
    
    for (int i = 0; i < n; i++) {
        for  (int p = 1;p < 1000000000/2; p++) {
            int x;
            x = a.at(i)*(p+0.5);
            if (  x <=m) res.at(x) ++;
            else {
                break;
            }
        }
    }
int result = 0;
    for (int i = 1; i <= m; i++) {
        if (res.at(i) == n) result++;
    }
    cout << result << endl;
}
