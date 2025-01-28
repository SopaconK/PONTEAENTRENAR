#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
using lli=long long int;
using ld=long double;


void solve(){
    lli n=1;
 //   deb(n);
    cin>>n;
   // deb(n);
    vector<ld> v1(n);
    vector<ld> v2(n);
    for(lli i=0; i<n; ++i){
        cin>>v1[i]>>v2[i];
     //   deb(v1[i]);
       // deb(v2[i]);
    }
    sort(v1.rbegin(), v1.rend());
    sort(v2.rbegin(), v2.rend());
    ld ans=0;
    ld aux=0;
    ld a=0;
    ld b=0;
    lli p1=0;
    lli p2=0;
    while(p1<n || p2<n){
    

        if(a<=b){
            if(p1<n){
                a+=v1[p1];
                p1++;
            }
            else{
                b+=v2[p2];
                p2++;
            }
        }
        else{
            if(p2<n){
                b+=v2[p2];
                p2++;
            }
            else{
                a+=v1[p1];
                p1++;
            }
        }
    //    deb(a);
  //      deb(b);
        aux=min(a,b);
        aux-=(p1+p2);
   //     deb(aux);
        ans=max(ans, aux);
    }
     cout<<setprecision(4)<<fixed<<ans<<endl;
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