#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b); for(int i=(a); i<=(b); i++) 
#define rep(i,n) for(int i = 0; i < (n); i++)
const int MOD = 1e9+7;
int gcd(int a, int b){ //a>=0,b>=0,￢(a=b=0)
  while(min(a,b)>0){if(a<b)swap(a,b);a=a%b;}return max(a,b);
}
char c[505][505];
bool reached[505][505];
bool ok=false;
int h,w;
void dfs(int x,int y){
  if((x<0||x>h-1)||(y<0||y>w-1)) return;
  if(reached[x][y]) return;
  if(c[x][y]=='#') return;
  if(c[x][y]=='g'){
    ok=1;
    return;
  }
  reached[x][y]=true;

  dfs(x,y-1);
  dfs(x,y+1);
  dfs(x+1,y);
  dfs(x-1,y);
}


signed main(){
  cin >> h>> w;
  rep(i,h){
    rep(j,w) cin>>c[i][j];
  }
  int tmpx,tmpy;
  rep(i,h){
    rep(j,w){
      if(c[i][j]=='s') {tmpx=i;tmpy=j;}
    }
  }
  
  dfs(tmpx,tmpy);
 // cout<<tmpx<<" "<<tmpy<<endl;
  if(ok) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
