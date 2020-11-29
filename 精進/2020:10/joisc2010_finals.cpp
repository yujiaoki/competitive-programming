#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
typedef long long int ll;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll INF=1000000010;
const ll LINF=4000000000000000010LL;
const int MAX=310;
const double EPS=1e-9;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct UnionFind{
    vector<int> par;
    vector<int> dep;
    
    UnionFind(int siz){
        par.assign(siz,0);
        dep.assign(siz,0);
        for(int i=0;i<siz;i++){
            par[i]=i;
        }
    };

    int find(int x){
        if(par[x]==x){
            return x;
        }else{
            return par[x]=find(par[x]);
        }
    }

    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y){
            return;
        }
        if(dep[x]<dep[y]){
            par[x]=y;
        }else{
            par[y]=x;
            if(dep[x]==dep[y]){
                dep[x]++;
            }
        }
    }

    bool same(int x,int y){
        return find(x)==find(y);
    }
};
struct edge{int from,to,cost;};
bool comp(const edge& e1,const edge& e2){
    return e1.cost<e2.cost;
}
//---------------------------------------------------------------------------------------------------

int main(void){
    // Your code here!
    int n,m,k; cin >> n >> m >> k;
    vector<edge> e;
    rep(i,m) {
        int a,b,c;  cin >> a >> b >> c;a--;b--;
        e.push_back({a,b,c});
    }
    int c = n;
    UnionFind uf(n);
    sort(all(e),comp);
    int ans = 0;
    rep(i,m) {
        if (c <= k) break;
        if (uf.same(e[i].from,e[i].to)) continue;
        uf.unite(e[i].from,e[i].to);
        c--;
        ans += e[i].cost;
    }
    cout << ans << endl;
}
