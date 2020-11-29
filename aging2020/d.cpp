#include <bits/stdc++.h>
#include <iostream>
#include <bitset>
#include <string>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
typedef long long ll;
const ll MOD=1000000007;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T>auto MAX(const T& a) { return *max_element(a.begin(),a.end()); }
template<class T>auto MIN(const T& a) { return *min_element(a.begin(),a.end()); }
template<class T, class U>U SUM(const T& a, const U& v) { return accumulate(a.begin(),a.end(), v); }
template<class T, class U>U COUNT(const T& a, const U& v) { return count(a.begin(),a.end(), v); }
template<class T, class U>int LOWER(const T& a, const U& v) { return lower_bound(a.begin(),a.end(), v) - a.begin(); }
template<class T, class U>int UPPER(const T& a, const U& v) { return upper_bound(a.begin(),a.end(), v) - a.begin(); }
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }
int LCM(int a, int b) { int g = GCD(a, b); return a / g * b; }
//---------------------------------------------------------------------------------------------------
template<int MOD> struct ModInt {
    static const int Mod = MOD; unsigned x; ModInt() : x(0) { }
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const { long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u); }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ostream& operator<<(ostream& st, const ModInt<MOD> a) { st << a.get(); return st; };
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r; }
template<typename T, int FAC_MAX> struct Comb { vector<T> fac, ifac;
    Comb(){fac.resize(FAC_MAX,1);ifac.resize(FAC_MAX,1);FOR(i,1,FAC_MAX-1)fac[i]=fac[i-1]*i;
        ifac[FAC_MAX-1]=T(1)/fac[FAC_MAX-1];for(int i=FAC_MAX-2;i>=1;i--)ifac[i]=ifac[i+1]*T(i+1);}
    T aPb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b]; }
    T aCb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b] * ifac[b]; }
    T nHk(int n, int k) { if (n == 0 && k == 0) return T(1); if (n <= 0 || k < 0) return 0;
        return aCb(n + k - 1, k); } // nHk = (n+k-1)Ck : n is separator
    T pairCombination(int n) {if(n%2==1)return T(0);return fac[n]*ifac[n/2]/(T(2)^(n/2));}
    // combination of paris for n
}; 
typedef ModInt<1000000007> mint;
int binary(int bina){
    int ans = 0;
    for (int i = 0; bina>0 ; i++)
    {
        ans = ans+(bina%2)*pow(10,i);
        bina = bina/2;
    }
    return ans;
}
int main(void){
    // Your code here!
    int n; cin >> n;
    string s; cin >> s;
    int co1  = 0;
    rep(i,n) {
        if (s[i] == '1') co1++;
    }
    reverse(all(s));
    int x1p = 0;
    if (find(all(s),'1') != s.end()) {
    int 2ama = 1;
    rep(i,n) {
        if (i != 0) {
            2ama *= 2;
            2ama %= (co1+1);
        }
        if (s[i] == '1') {
            x1p += 2ama;
            x1p %= (co1+1);
        }
    }
    }
    int x1m = 0;
    if (find(all(s),'1') != s.end()) {
    2ama = 1;
    rep(i,n) {
        if (i != 0) {
            2ama *= 2;
            2ama %= (co1-1);
        }
        if (s[i] == '1') {
            x1m += 2ama;
            x1m %= (co1-1);
        }
    }
    }
    for (int i = n-1 ; i >= 0;i--) {
        string si = s;
        ll ans = 0;
        int xi = 0;
        if(si[i] == '1') {
            xi = x1m;
            
            }
        } else {
            xi = x1p;
            si[i] = '1';
            co1i++;
        }

        while(find(all(si),'1') != si.end()) {
            ans++;
            int 2joama = 1;
            rep(j,si.size()) {
                int cnt = 0;
                if (j != 0) {
                        2joama *=2;
                        2joama %= co1i;
                    }
                if (si[j] == '1') {
                    cnt += 2joama % co1i;
                    cnt % co1i;
                }
            }
            si = 
        }
        cout << ans << endl;
    }
}
