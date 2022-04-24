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

int calc(string s, string t)
{
    int i = 0;
    int ans = 0;
    while (s != t && i < s.size())
    {
        if (s[i] != t[i])
        {
            queue<int> que; // j より前にあるsとtで異なるインデックスを小さい順に保時
            que.push(i);
            int j = i + 1;
            while (!que.empty())
            {
                int k = que.front();
                que.pop();
                while (j < s.size())
                {
                    if (s[k] == s[j])
                    {
                        if (s[j] != t[j])
                        {
                            que.push(j);
                        }
                        j++;
                    }
                    else
                    {
                        if (s[j] == t[j])
                        {
                            que.push(j);
                        }
                        break;
                    }
                }
                swap(s[k], s[j]);
                ans++;
            }
            i = j;
        }
        else
        {
            i++;
        }
        // cout << s << endl;
    }
    if (s != t)
        ans = INF;
    return ans;
}
int main(void)
{
    // Your code here!
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cnt_s = 0, cnt_t = 0;
    rep(i, s.size())
    {
        if (s[i] == '0')
            cnt_s++;
        if (t[i] == '0')
            cnt_t++;
    }
    if (cnt_s != cnt_t)
    {
        cout << -1 << endl;
        return 0;
    }
    int ans = calc(s, t);
    string s_r = s;
    string t_r = t;
    reverse(all(s_r));
    reverse(all(t_r));
    ans = min(ans, calc(s_r, t_r));
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
}
