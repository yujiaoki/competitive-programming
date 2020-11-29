#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)


const int MAX = 10000000;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(void){
    // Your code here!
    COMinit();
    int x,y; cin >> x >> y;
    if ((x+y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    if ((2*y - x) % 3 != 0 || (2*x-y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    int a = (2*y-x)/3;
    int b = (2*x-y)/3;
    long long ans = COM(a+b,b);
    cout << ans << endl;
}
