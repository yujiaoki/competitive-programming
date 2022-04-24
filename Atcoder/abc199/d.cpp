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
vb check;
ll ans = 1;
vvll G;
// void dfs(ll par, ll cnt)
// {
//     if (check[par])
//         return;
//     check[par] = true;
//     if (cnt == 3)
//     {
//         ans *= 3;
//         rep(i, G[par].size())
//         {
//             if (check[G[par][i]] == false)
//             {
//                 dfs(G[par][i], cnt - 1);
//                 cnt--;
//             }
//         }
//     }
//     else
//     {
//         ans *= cnt;
//         cnt = 2;
//         rep(i, G[par].size())
//         {
//             if (check[G[par][i]] == false)
//             {
//                 dfs(G[par][i], cnt);
//                 cnt--;
//             }
//         }
//     }

//     // int m = G[par].size();
//     // rep(i,G[par].size()) {
//     //     if (check[G[par][i]] == )
//     // }
//     // if (G[par].size() - 1 >= 3)
//     // {
//     //     ans = 0;
//     //     return;
//     // }
//     // else if (G[par].size() - 1 == 2)
//     // {
//     //     int
//     //         rep(i, G[par].size())
//     //     {
//     //         if (check[G[par][i]] == false)
//     //         {
//     //         }
//     //     }
//     // }
//     // } else {
//     //     if (G[par].size() >= 3) {
//     //         ans = 0;
//     //         return;
//     //     }
//     //     else if (G[par].size() == 2) {
//     //         ans*= 2;
//     //     } else {

//     //     }
//     // }
// }

int main(void)
{
    // Your code here!
    ll n, m;
    cin >> n >> m;
    G.resize(n);
    check.resize(n);
    rep(i, n) check[i] = false;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[b].push_back(a);
        G[a].push_back(b);
    }

    rep(i, n)
    {
        if (!check[i])
        {
            ans *= 3;
            priority_queue<int> que;
            que.push(i);
            while (!que.empty())
            {
                int v = que.top();
                que.pop();
                int cnt = 2;
                if (check[v] == true)
                    continue;
                check[v] = true;
                rep(j, G[v].size())
                {
                    if (!check[G[v][j]])
                    {
                        ans *= cnt;
                        check[G[v][j]] = true;
                        que.push(G[v][j]);
                    }
                    cnt--;
                }
            }
        }
    }
    cout << ans << endl;
}
