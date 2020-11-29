#include <bits/stdc++.h>
using namespace std;

int facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}
int main(void){
    // Your code here!
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    vector<int> init(n);
    for (int i = 1; i <= n; i++) {
        init.at(i) = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> p.at(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> q.at(i);
    }
    int a = 1;
    int b = 1;
    for (int i =0; i<n;) {
        for (int j=1;j <=9;j++) {
            if(p.at(i) == j) {
                i++;
                cout << "if" <<endl;
                break;
            }
            else {
                a += facctorialMethod(n-1-i);
                cout << "else" <<endl;
            }
        }
    }


    cout << a << endl;
    
}