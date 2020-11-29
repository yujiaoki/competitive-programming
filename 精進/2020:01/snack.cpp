#include <bits/stdc++.h>
using namespace std;

int main(void){
    // Your code here!
    int64_t a , b;
    cin >> a >> b;
    int64_t result = 1;
    if (a > b) result =a;
    else result = b;
    if (abs(a-b) == 1) result = a*b;
    else {
        for (int i = 1;;i++) {
            if( result*i % a == 0 && result*i % b == 0) {
                result = result*i;
                break;
            }
    }
    }
    cout << result << endl;
}