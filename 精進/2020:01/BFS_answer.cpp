//https://atcoder.jp/contests/abc007/tasks/abc007_3
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
struct v{
  int y,x,l;
};
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int main(){
  int R,C,sy,sx,gy,gx;
  cin>>R>>C>>sy>>sx>>gy>>gx;
  sy--,sx--,gy--,gx--;
  vector<string> c(R);
  for(int i=0;i<R;i++)
    cin>>c[i];
  queue<v> Q;
  Q.push({sy,sx,0});
  while(!Q.empty()){
    v p = Q.front();
    Q.pop();
    for(int i=0;i<4;i++){
      int ny = p.y + dy[i];
      int nx = p.x + dx[i];
      if(ny == gy && nx == gx){
        cout<<p.l+1<<endl;
        return 0;
      }
      if(c[ny][nx] == '.'){
        Q.push({ny,nx,p.l+1});
        c[ny][nx] = '#';
      }
    }
  }
  return 0;
}
