#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, n) for(int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize("Ofast")
using namespace std;
typedef int64_t ll;
typedef long double ld;
const ll INF=(1LL<<60);
const ld inf=pow(10,10);
const ld pi=acosl((ld)1);
//const ll mod = 1000000007;
const ll mod = 1000003;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int ddx[8]={1,0,-1,-1,-1,0,1,1};
const int ddy[8]={1,1,1,0,-1,-1,-1,0};
struct UnionFind {
  vector< int > data;
 
  UnionFind(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
};

void solve(){
  ll n,k,m;cin>>n>>m>>k;
  vector<ll>A(m);
  vector<ll>B(m);
  vector<ll>C(k);
  vector<ll>D(k);
  vector<ll>count(n,0);
  vector<ll>count2(n,0);
  vector<ll>G[n];
  vector<pair<ll,ll>>v;
  rep(i,m){
    cin>>A[i]>>B[i];
    A[i]--;
    B[i]--;
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
    v.push_back(make_pair(A[i],B[i]));
    v.push_back(make_pair(B[i],A[i]));
  }
  UnionFind uf(n);
  rep(i,m){
    uf.unite(A[i],B[i]);
  }
  sort(all(v));
  rep(i,k){
    cin>>C[i]>>D[i];
        C[i]--;
    D[i]--;
    if(uf.find(C[i])!=uf.find(D[i]))continue;

    count[C[i]]++;
    count[D[i]]++;
    if(binary_search(all(v),make_pair(C[i],D[i]))){
      count2[C[i]]++;
      count2[D[i]]++;
    }
  }
  rep(i,n){
    ll ans=uf.size(i);
    ans--;
    ans-=count[i];
    ans-=(ll)G[i].size();
    ans+=count2[i];
    cout<<ans<<" ";
  }
  cout<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout<<fixed;
	cout<<setprecision(30);
	solve();
}
