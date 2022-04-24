#include <bits/stdc++.h>
// #include<atcoder/all>
// using namespace atcoder;
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
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int,int> P;
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
const int PERIMETER = 4e8;
//---------------------------------------------------------------------------------------------------
// void solve() {
//     int N; cin >> N;

// }
// int BinarySearch(vector<ll> vec, int key) {
//     // key: 検索対象の値
//     int left = 0, right = vec.size(), mid;

//     while (left < right) {
//         mid = (left + right)/2;
//         if (vec[mid].first == key) {
//             return mid;
//         } else if (key < vec[mid].first) {
//             // 半分より下
//             right = mid;
//         } else if (vec[mid].first < key) {
//             // 半分より上
//             // 必要ないが，分かりやすいように条件を記述してある．
//             left = mid + 1;
//         }
//     }
//     // key が配列の中に見つからない場合
//     return -1;
// }

int main(void){
    // Your code here!
    int t; cin >> t;
    // long long ret = 0;
    ll count = 0;
    vector<ll> vec;
    for (int m = 1; m * m < PERIMETER; m++) {
        for (int n = 1; n < m && n * n + m * m <= PERIMETER; n++) {
            if (m % 2 == n % 2) continue;
            if (GCD(m, n) > 1) continue;
            int a = m * m - n * n;
            int b = 2 * m * n;
            int c = m * m + n * n;
            if (c == a*a - b) {
                count++;
                vec.push_back(c);
            }
            // ret += PERIMETER / (a + b + c);
        }
    }
    Sort(vec);
    while(t--) {
        // solve();
        int N; cin >> N;
        int ret_i = LOWER(vec,N);
        cout << ret_i << endl;
    }
}
