#include<bits/stdc++.h>
using namespace std;
#define pb push_back
using lli=long long int;
#define deb(x) cout<<#x<<": "<<x<<endl;
//#define endl '\n'
using ld=long double;


lli bs (vector<ld> &v, ld x){ //Find the number of elements of v that are >= x 
    lli l=0;
    lli r=v.size();
    while(r-l>1){
        
        lli m=(l+r)/2;
//        deb(l);
  //      deb(r);
    //    deb(m);
      //  deb(v[m]);
        if(v[m]>=x) r=m;
        else l=m;
    }
//    deb(l);
  //  deb(v[l]);
    if(v[l]<x) l++; 
    return v.size()-l;

}

void solve(){
    lli n,m,k;
    cin>>n>>m>>k;
    k=n*m-k+1;
    vector<lli> a (n);
    vector<lli> b (n);
    vector<lli> c (m);
    vector<lli> d (m);
    for(lli i=0; i<n; ++i){
        cin>>a[i]>>b[i];
        b[i]+=a[i];
    }
    for(lli i=0; i<m; ++i){
        cin>>c[i]>>d[i];
        d[i]+=c[i];
    }

    ld l=0;
    ld r=1;
    lli cont=64;
    while(cont--){
        ld p=(l+r)/2;
        //deb(p);
        vector<ld> v (n);
        for(lli i=0; i<n; ++i){
            v[i]=p*b[i]-a[i];
          //  deb(v[i]);
        }
        sort(v.begin(), v.end());
        lli ans=0;
        for(lli i=0; i<m; ++i){
            ld x=c[i]-(ld) p*d[i];
            //deb(x);
            ans+=bs(v, x);
            //deb(ans);
        }
       // deb(ans);
        if(ans>=k){
            r=p;
        }
        else{
            l=p;
        }
    }
    cout<<fixed<<setprecision(16)<<100*r<<endl;

}




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
}