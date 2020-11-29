#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;
const ll MOD=1000000007;

int main()
{
  int N, M;
  ll res=1;
  cin >> N >> M;

  vector<bool> broken(N+1,false);
  rep(i,M) {
    int a;
    cin >> a;
    broken[a]=true;
  }

  ll dp[110000];
  rep (i,N) dp[i] = 0;
  dp[0]=1;
  rep (i,N){
    if(!broken[i+1] && i+1<=N){
      dp[i+1] += dp[i];
      dp[i+1] %= MOD;
    }
    if(!broken[i+2] && i+2<=N){
      dp[i+2] += dp[i];
      dp[i+2] %= MOD;
    }
  }

  cout << dp[N] << endl;
  return 0;
}
