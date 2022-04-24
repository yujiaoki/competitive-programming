#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

template <class T>
std::vector<T> vec(int len, T elem)
{
    return std::vector<T>(len, elem);
}

using ll = long long;
constexpr ll INF = 1LL << 60;

int main()
{
    int a, b;
    ll k;
    cin >> a >> b >> k;
    std::string s;
    rep(i, a) s[i] = 'a';
    rep(i, b) s[i] = 'b';
    int n = s.length();

    auto next = vec(26, n);
    auto dp = vec(26, vec(n + 1, 0LL));

    for (int i = n - 1; i >= 0; --i)
    {
        next[s[i] - 'a'] = i;

        for (int c = 0; c < 26; ++c)
        {
            int j = next[c];
            if (j == n)
                continue;

            dp[c][i] = 1;
            for (int d = 0; d < 26; ++d)
            {
                dp[c][i] = std::min(dp[c][i] + dp[d][j + 1], INF);
            }
        }
    }

    --k;

    int idx = 0;
    while (idx < n)
    {
        int c;
        for (c = 0; c < 26; ++c)
        {
            if (dp[c][idx] <= k)
            {
                // 先頭cにk番目はないのでパス
                k -= dp[c][idx];
            }
            else
            {
                std::cout << char(c + 'a');

                while (s[idx] != c + 'a')
                    ++idx;
                ++idx;

                --k; // empty string
                break;
            }
        }

        if (k < 0)
        {
            std::cout << std::endl;
            break;
        }

        if (c == 26)
        {
            // k番目はなし
            std::cout << "Eel" << std::endl;
            break;
        }
    }
}
