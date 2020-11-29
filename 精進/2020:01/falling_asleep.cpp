#include <bits/stdc++.h>
using namespace std;

int main(void){
    // Your code here!
    int n;
    cin >>n;
    vector<string> s(n);
    vector<int> t(n);
    for (int i = 0 ; i < n; i++) {
        cin >> s.at(i) >> t.at(i);
    }
    string x;
    cin >> x;
    int x_ind;
    for (int i = 0 ; i < n; i++) {
        if (s.at(i) == x){
            x_ind = i;
            break;
        }
    }
    int sum=0;
    for (int i = x_ind+1;i <n;i++) {
        sum+=t.at(i);
    }
    cout << sum << endl;
}