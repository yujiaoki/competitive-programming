#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) v.begin(),v.end()
constexpr ll MOD=998244353;
constexpr ll INF=2e18;
//---------------------------------------------------------------------------------------------------
template<typename X>
struct Segtree{
    using F=function<X(X,X)>;
    int n; F f; X ex;
    vector<X> dat;
    Segtree(int n_, F f, X ex)
        :f(f), ex(ex){
        n=1;
        while(n_>n){n*=2;}
        dat.assign(2*n,ex);
    }
    void set(int i, X x){
        dat[i+n-1]=x;
    }
    void build(){
        for(int k=n-2;k>=0;k--) 
            dat[k]=f(dat[2*k+1],dat[2*k+2]);
    }
    void update(int i, X x){
        i+=n-1;
        dat[i]=x;
        while(i>0){
            i=(i-1)/2;
            dat[i]=f(dat[i*2+1],dat[i*2+2]);
        }
    }
    X query(int a, int b){
        return query_sub(a,b,0,0,n);
    }
    X query_sub(int a, int b, int k, int l, int r){
        if(r<=a||b<=l)
            return ex;
        else if(a<=l&&r<=b)
            return dat[k];
        else{
            X vl=query_sub(a,b,k*2+1,l,(l+r)/2);
            X vr=query_sub(a,b,k*2+2,(l+r)/2,r);
            return f(vl,vr);
        }
    }
};

VI f(VI a, VI b){
    VI ret(3);
    ret[0]=max(a[0],b[0]);
    VI c={a[1],a[2],b[1],b[2]};
    sort(ALL(c));
    ret[1]=c[0];
    ret[2]=c[1];
    return ret;
}

int main(){
    int n; cin >> n;
    VI a(n); REP(i,n) cin >> a[i];
    VI e={0,INF,INF};
    Segtree<VI> seg(n,f,e);
    REP(i,n)
        seg.set(i,{a[i],a[i],INF});
    seg.build();
    int l=0, r=1;
    ll ans=0;
    REP(i,n){
        ans+=r-i;
        for(int j=r+1;j<n;j++){
            VI ret=seg.query(i,j+1);
            if(ret[0]>ret[1]+ret[2]){
                r=j-1;
                break;
            }
            ans++;
            if(j==n-1)
                r=n-1;
        }
    }
    cout << ans << endl;
    return 0;
}
}
