//https://qiita.com/drken/items/996d80bcae64649a6580
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
typedef long long ll;
const ll MOD=1000000007;
using namespace std;
using Graph = vector<vector<int>>;

int main(void){
    // Your code here!
    int n,m;  cin >> n >> m;


Graph G(n);
rep(i,m) {
    int a,b ; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
}

vector<int> dist(n,-1);
queue<int> que;

dist[0] =0;
que.push(0);

while(!que.empty()) {
    int v = que.front();
    que.pop();

    for (int nv : G[v]) {
        if (dist[nv] != -1) continue;

        dist[nv] =dist[v] +1;
        que.push(nv);
    }
}

FOR(v,1,n-1) cout << v << ": " << dist[v] << endl;

}