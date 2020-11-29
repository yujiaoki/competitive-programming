#include <bits/stdc++.h>
using namespace std;

int kaijyo(int k) {
    if (k ==1) return 1;
    else {
        return k*kaijyo(k-1);
    }
}
int main(void){
    // Your code here!
    int n;
    cin >> n;
    vector<long long> x(n+1);
    for ( int i = 1 ; i <= n ; i++) {
        cin >> x.at(i);
    }
    long long  sum = 0;
    for (int i = 1; i < n;i++) {
        for (int  j =1; j <= i;j++) {
            sum+=(x.at(i+1)-x.at(i))*kaijyo(n-1)/j;
        }
    }
    int result;
    result = sum % (1000000000+7);
    cout << result << endl;
}