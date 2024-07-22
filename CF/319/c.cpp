#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
using lli=long long int;
using ld=long double;




struct line{
    lli m;
    lli b;
    lli eval (lli x){
        return m*x+b;
    }
    ld intersect (line l){
        return (ld) (l.b-b)/(m-l.m);
    }

};
void solve(){
    lli n;
    cin>>n;
    vector<lli> a (n);
    vector<lli> b(n);
    for(lli i=0; i<n; ++i){
        cin>>a[i];
    }
    for(lli i=0; i<n; ++i){
        cin>>b[i];
    }

    deque<line> dq;
    dq.push_back({b[0], 0});
    lli ans=0;
    for(lli i=1; i<n; ++i){
        //deb(dq[0].eval(a[i]));
        if(dq.size()>=2){
      //      deb(dq[1].eval(a[i]));
        }
        while(dq.size()>=2 && dq[0].eval(a[i])>=dq[1].eval(a[i])){
    //        deb(a[i]);
            dq.pop_front();
        }
        lli f=dq[0].eval(a[i]);
  //      deb(f);
        if(i==n-1){
            ans=f;
        }
//        deb(b[i]);
        line aux ={b[i], f};
        while(dq.size()>=2 && dq.back().intersect(aux)<= dq[dq.size()-2].intersect(dq.back())){
            dq.pop_back();
        }
        dq.push_back(aux);
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}