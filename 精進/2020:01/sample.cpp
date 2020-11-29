#include <bits/stdc++.h>
using namespace std;
//
int main(void){
    // Your code here!
    int N;
    vector<int> d(110);
    cin >> N;
    for (int i = 0; i < N ; i++)  cin >> d.at(i);
    vector<int> num(110,0);
    for (int i = 0; i < N ; i++) {
        num.at(d.at(i))++;
    }
    
    int res = 0 ;
    for (int i = 0; i <= 100 ; i++) {
        if (num.at(i)) {
            res++;
        }
        }
        cout << res <<endl;
}