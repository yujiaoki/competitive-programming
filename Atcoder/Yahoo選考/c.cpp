#include <bits/stdc++.h>
// #include <iostream>
// #include <string>
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

int main(int argc, char *argv[])
{
    // このコードは標準入力と標準出力を用いたサンプルコードです。
    // このコードは好きなように編集・削除してもらって構いません。
    // ---
    // This is a sample code to use stdin and stdout.
    // Edit and remove this code as you like.
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k > 0 && s[0] == 'S' && s[2] == 'S')
    {
        s[0] = '.';
        s[1] = '.';
        s[2] = '.';
        k--;
    }
    if (k > 0 && s[n - 1] == 'S' && s[n - 3] == 'S')
    {
        s[n - 1] = '.';
        s[n - 2] = '.';
        s[n - 3] = '.';
        k--;
    }
    // 隣あう2人とも指揮が下がってる
    rep(i, n)
    {
        if (i == 0 || i == n - 1)
            continue;
        if (k > 0 && s[i] == 'S' && s[i + 1] == 'S' && s[i - 1] == 'S')
        {
            k--;
            s[i] = '.';
            s[i + 1] = '.';
            s[i - 1] = '.';
            i++;
        }
    }
    // 隣あう2人とも士気が下がっている
    rep(i, n - 1)
    {
        if (k > 0 && s[i] == 'S' && s[i + 1] == 'S')
        {
            k--;
            s[i] = '.';
            s[i + 1] = '.';
            i++;
        }
    }
    // 一人だけ士気が下がっている
    rep(i, n)
    {
        if (k > 0 && s[i] == 'S')
        {
            k--;
            s[i] = '.';
        }
    }
    int ans = 0;
    rep(i, n) if (s[i] == '.') ans++;
    // rep(i, n) cout << s[i] << endl;
    cout << ans << endl;
}
