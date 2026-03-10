#include<bits/stdc++.h>
using namespace std;
using lli=int;
#define deb(x) cout<<#x<<": "<<x<<endl;
#define pb push_back
#define endl '\n'

void solve(){
    lli n;
    cin>>n;
    vector<vector<lli>> v (n);
    for(lli i=0; i<n; ++i){
        lli a,t;
        cin>>a>>t;
        t--;
        v[t].pb(a);
    }
    for(lli i=0; i<n; ++i){
        sort(v[i].rbegin(), v[i].rend());
    }
    lli maxi1=-1e17;
    lli maxi2=-1e17;
    lli ind1=-1;
    lli ind2=-1;
    for(lli i=0; i<n; ++i){
        if(v[i].size()>0){
            if(v[i][0]>maxi1){
                maxi2=maxi1;
                ind2=ind1;
                maxi1=v[i][0];
                ind1=i;
            }
            else if(v[i][0]>maxi2){
                maxi2=v[i][0];
                ind2=i;
            }
        }
    }
    lli ans=0;
    for(lli i=0; i<n; ++i){
        if(i!=ind1){
            for(lli j=0; j<v[i].size(); ++j){
                if(maxi1+v[i][j]>0){
                    ans+=maxi1+v[i][j];
                }
                else{
                    break;
                }
            }
        }
        else{
            for(lli j=1; j<v[i].size(); ++j){
                 if(maxi2+v[i][j]>0){
                    ans+=maxi2+v[i][j];
                }
                else{
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    //cin>>t;
    while(t--) solve();
}