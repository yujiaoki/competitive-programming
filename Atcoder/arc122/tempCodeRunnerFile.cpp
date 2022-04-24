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
bool is_integer(double x)
{
    return std::floor(x) == x;
}
int main(void)
{
    // Your code here!
    int k, n, m;
    cin >> k >> n >> m;
    vi a(k);
    rep(i, k) cin >> a[i];
    int cnt = 0; // 繰り上げた回数
    vi b(k);
    vb check(k, false);
    rep(i, k)
    {
        if ((double)m * a[i] / n - m * a[i] / n >= 0.5)
        {
            cnt++;
            b[i] = ceil((double)m / n * a[i]);
            check[i] = true;
            // 繰り上げされたかどうか
        }
        else
        {
            if (is_integer(m * a[i] / n))
            {
                b[i] = m * a[i] / n;
                continue;
            }
            b[i] = floor((double)m / n * a[i]);
            cnt--;
        }
    }
    if (cnt == 0)
    {
        b[0]++;
    }
    else if (cnt > 1)
    {
        vector<pair<double, int>> lis;
        rep(i, k)
        {
            if (check[i] == true)
            {
                lis.push_back({1 - (double)m * a[i] / n - m * a[i] / n, i});
            }
        }
        Sort(lis);
        int j = 0;
        while (cnt > 1)
        {
            cnt--;
            b[j]--;
            j++;
        }
    }
    rep(i, k) cout << b[i] << " ";
}
