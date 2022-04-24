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
vector<pair<ll, ll>> prime_factorize(ll n)
{
    vector<pair<ll, ll>> res;
    for (ll p = 2; p * p <= n; ++p)
    {
        if (n % p != 0)
            continue;
        int num = 0;
        while (n % p == 0)
        {
            ++num;
            n /= p;
        }
        res.push_back(make_pair(p, num));
    }
    if (n != 1)
        res.push_back(make_pair(n, 1));
    return res;
}
bool is_prime(const unsigned n)
{
    switch (n)
    {
    case 0: // fall-through
    case 1:
        return false;
    case 2: // fall-through
    case 3:
        return true;
    } // n > 3 が保証された

    if (n % 2 == 0 || n % 3 == 0)
        return false;
    // n は 2 と 3 のいずれの倍数でもないことが保証された
    // これより n は (6の倍数)-1 か (6の倍数)+1 である

    // 6の倍数前後の数を使って試し割りをする
    for (unsigned i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0)
            return false; // (6の倍数)-1
        if (n % (i + 2) == 0)
            return false; // (6の倍数)+1
    }

    return true;
}

int main(void)
{
    // Your code here!
    ll n, m;
    cin >> n >> m;
    set<ll> st;
    rep(i, n)
    {
        ll a;
        cin >> a;
        vector<pair<ll, ll>> ls = prime_factorize(a);
        rep(i, ls.size())
        {
            if (st.find(ls[i].first) == st.end())
            {
                st.insert(ls[i].first);
            }
        }
    }
    vll primes;
    primes.push_back(1);
    ll k = 2;
    while (k <= m)
    {
        if (is_prime(k))
        {
            primes.push_back(k);
        }
        k++;
    }
    vll ans;
    // rep(i, primes.size())
    // {
    //     if (st.find(primes[i]) == st.end())
    //     {
    //         ans.push_back(primes[i]);
    //     }
    // }
    FOR(i, 1, m)
    {
        if (is_prime(i))
        {
            if (st.find(i) == st.end())
            {
                ans.push_back(i);
            }
        }
        else
        {
            vector<pair<ll, ll>> ls = prime_factorize(i);
            bool res = true;
            rep(j, ls.size())
            {
                if (st.find(ls[j].first) != st.end())
                {
                    res = false;
                }
            }
            if (res)
                ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    rep(i, ans.size())
    {
        cout << ans[i] << endl;
    }
}
