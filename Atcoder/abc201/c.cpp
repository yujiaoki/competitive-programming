#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, start, end) for (int i = start; i <= end; i++)
const int INF = 1001001001;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
typedef long long ll;
const ll MOD = 1000000007;
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
auto MAX(const T &a) { return *max_element(a.begin(), a.end()); }
template <class T>
auto MIN(const T &a) { return *min_element(a.begin(), a.end()); }
template <class T, class U>
U SUM(const T &a, const U &v) { return accumulate(a.begin(), a.end(), v); }
template <class T, class U>
U COUNT(const T &a, const U &v) { return count(a.begin(), a.end(), v); }
template <class T, class U>
int LOWER(const T &a, const U &v) { return lower_bound(a.begin(), a.end(), v) - a.begin(); }
template <class T, class U>
int UPPER(const T &a, const U &v) { return upper_bound(a.begin(), a.end(), v) - a.begin(); }
int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }
int LCM(int a, int b)
{
    int g = GCD(a, b);
    return a / g * b;
}
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
typedef vector<vll> vvll;
typedef map<int, int> mii;
typedef set<int> si;
//---------------------------------------------------------------------------------------------------
long long combi(long long n, long long k)
{
    if (n == k || k == 0)
        return 1;
    else
    {
        return combi(n - 1, k - 1) + combi(n - 1, k);
    }
}
ll permutationMethod(ll n, ll r)
{
    r = n - r;
    ll sum = 1;
    ll i;
    for (i = n; i >= r + 1; i--)
        sum *= i;
    return sum;
}

int main(void)
{
    // Your code here!
    string s;
    cin >> s;
    ll cnt_o = 0, cnt_hate = 0, cnt_x = 0;
    rep(i, 10)
    {
        if (s[i] == 'o')
            cnt_o++;
        if (s[i] == 'x')
            cnt_x++;
        if (s[i] == '?')
            cnt_hate++;
    }
    if (cnt_o > 4)
    {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    // if (cnt_o == 0)
    //     ans = permutationMethod(4, cnt_o) * (cnt_o + cnt_hate) - pow(cnt_hate, 2) * 4;
    // // ans = pow(cnt_o + cnt_hate, 4) - pow(cnt_hate + cnt_o - 1, 4) * cnt_o;
    // if (cnt_o == 0)
    // {
    //     ans = permutationMethod(4, 4);
    // }
    // else if (cnt_o == 1)
    for (int i = 0; i < 10000; i++)
    {
        vi check(10, 0);
        rep(j, 10)
        {
            if (s[j] == 'o')
                check[j]++;
        }
        string k = to_string(i);
        while (k.size() < 4)
        {
            k = '0' + k;
        }
        bool out = false;
        rep(j, 4)
        {
            int ind = k[j] - '0';
            if (s[ind] == 'x')
            {
                out = true;
                break;
            }
            if (s[ind] == 'o')
                check[ind] = 0;
        }
        if (MAX(check) != 0)
            out = true;
        if (!out)
            ans++;
    }
    // ans = pow(cnt_o + cnt_hate, 4) - pow(cnt_hate, 4) * cnt_o;
    cout << ans << endl;
}
