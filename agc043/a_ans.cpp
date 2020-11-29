#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
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

int h,w;

void solve(vector<string> &board , vector<vector<int>> &min_vv,int x,int y,int count, bool streak){
    if (x < 0 || x > w-1 || y < 0 || y > h-1)return;
    if (board.at(y).at(x) == '#'){
        if(streak);
        else{
            count++;
            streak = true;
        }
    }
    else streak = false;
    if (count >= min_vv.at(y).at(x))return;
    min_vv.at(y).at(x) = count;

    solve(board,min_vv,x+1,y,count,streak);
    solve(board,min_vv,x,y+1,count,streak);
}



int main(void){
    // Your code here!
    cin >> h>> w;
    vector<string> board(h);
    vector<vector<int>> min_vv(h,vector<int>(w,10000));
    rep(i,h) cin >> board.at(i);
    solve(board,min_vv,0,0,0,false);
    cout << min_vv.at(h-1).at(w-1) << endl;

}
