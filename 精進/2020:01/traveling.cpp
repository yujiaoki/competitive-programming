#include <bits/stdc++.h>
using namespace std;

int main(void){
    // Your code here!
    int n;
    cin >> n;
    vector<int> t(n+1);
    vector<int> x(n+1);
    vector<int> y(n+1);
    t.at(0) = 0;
    x.at(0) = 0;
    x.at(0) = 0;
    for (int i = 1 ; i <= n ; i++) {
        cin >> t.at(i) >> x.at(i) >> y.at(i);
    }
   
    bool can = true;
    for (int j = 1; j <=n; j++) {
        int dt = t.at(j) - t.at(j-1) ;
        int dis = abs(x.at(j)-x.at(j-1)) + abs(y.at(j)-y.at(j-1));
        if (dt <dis) can = false;
        if (dt % 2 != dis %2 ) {
                can = false;
            }
           
    }
    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;
    }
  