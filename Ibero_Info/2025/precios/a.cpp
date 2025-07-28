#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define endl '\n'
#define deb(x) cout<<#x<<": "<<x<<endl;
vector<lli> p;
vector<vector<lli>> sons;
vector<lli> v1;
vector<lli> v2;
vector<lli> v3;
const lli MOD=1e9+7;
lli binexp(lli b, lli pow){
    if(pow==0) return 1;
    if(pow==1) return b%MOD;
    lli x=binexp(b, pow/2);
    x*=x;
    x%=MOD;
    if(pow%2){
        x*=b;
        x%=MOD;
    }
    return x;
}

lli inv(lli x){
    return binexp(x, MOD-2);
}
lli c=0;
lli ans=1;
void dfs(lli x){
    v1[x]=c;
    v3[c]=x;
    c++;
    for(lli i: sons[x]){
        dfs(i);
    }
    for(lli i=0; i<sons[x].size(); ++i){
        sons[x][i]=v1[sons[x][i]];
    }
    v2[x]=c;
    v3[c]=x;
    c++;
}

lli next(lli x, lli s){
    if(v1[s]<v1[x] || v2[x]<v2[s]){
        return p[x];
    }
    
    lli le=0;
    s=v1[s];
    lli ri=sons[x].size();
    while(ri-le>1){
        lli m=(le+ri)/2;
        if(sons[x][m]<=s) le=m;
        else ri=m;
    }
    
    return v3[sons[x][le]];  
    
}

vector<lli> dsu;
vector<lli> l;
vector<lli> r;
lli par(lli x){
    if(dsu[x]==x) return x;
    return dsu[x]=par(dsu[x]);
}




void merge(lli a, lli b){
    a=par(a);
    b=par(b);
    if(a==b) return;
    ans*=inv(r[a]-l[a]+1);
    ans%=MOD;
    ans*=inv(r[b]-l[b]+1);
    ans%=MOD;
   // deb(ans);
    lli le=max(l[a], l[b]);
    lli ri=min(r[a],r[b]);
    dsu[a]=b;
    l[b]=le;
    r[b]=ri;
    if(r[b]>=l[b]) ans*=(r[b]-l[b]+1);
    else ans=0;
    ans%=MOD;
}




void check(lli &a,lli &b, lli &c, lli &d){
 //   deb(a);
 //   deb(b);
  //  deb(c);
 //   deb(d);
    merge(a,c);
    if(a==b) return;
    a=next(a,b);
    c=next(c,d);
    check(a,b,c,d);
}

lli n;

lli ans2(){
    lli aux=1;
    for(lli i=0; i<n; ++i){
        if(par(i)==i){
  //          deb(i);
    ///        deb(r[i]);
    //     deb(l[i]);
            if(r[i]>=l[i]){
                aux*=(r[i]-l[i]+1);
            }
            else aux*=0;
            aux%=MOD;
        }
    }
    return aux;
}



void solve(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // lli n;
    cin>>n;
    p.resize(n);
    sons.resize(n);
    v1.resize(n);
    v2.resize(n);
    v3.resize(2*n);
    p[0]=-1;
    for(lli i=1; i<n; ++i){
        cin>>p[i];
        p[i]--;
        sons[p[i]].pb(i);
 //       deb(i);
    }
    dfs(0);

    dsu.resize(n);
    l.resize(n);
    r.resize(n);

    

    for(lli i=0; i<n; ++i){
        dsu[i]=i;
        cin>>l[i]>>r[i];
      //
      //   deb(i);
    }
        ans=ans2();

   //     deb(ans);
    lli m;
    cin>>m;
    while(m--){
        lli a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;
        b--;
        c--;
        d--;
        check(a,b,c,d);
        cout<<ans<<endl;

    }
    
    

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}