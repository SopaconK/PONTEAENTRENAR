#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define deb(x) cout<<#x<<": "<<x<<endl;
#define pb push_back
#define endl '\n'


void solve(){
    lli n,q;
    cin>>n>>q;
    vector<lli> pt (n+1);
    pt[0]=1;
    for(lli i=1; i<=n; ++i) pt[i]=pt[i-1]*3;
    vector<vector<lli>> v (n+1, vector<lli> (0,0));
    for(lli i=n; i>=0; --i){
        v[i].resize(pt[i]);
        if(i==n){
            for(lli j=0; j<pt[i]; ++j){
                char c;
                cin>>c;  //PORQUE YA NO SE SABE SI VIENE TODO PEGADO O CON ESPACIOS
                if(c=='A') v[i][j]=1;
                else v[i][j]=-1;
            }
        }
        else{
            
            for(lli j=0; j<pt[i]; ++j){
                for(lli cant=0; cant<3; ++cant){
                    if(v[i+1][3*j+cant]>0) v[i][j]++;
                    else v[i][j]--;
                }
            }
        }   
    }
    while(q--){
        lli x;
        
        cin>>x;
        x--;
    //    deb(x);
        for(lli i=n; i>=0; --i){
            if(i==n){
                if(v[i][x]==1) v[i][x]=-1;
                else v[i][x]=1;
            }
            else{
                v[i][x]=0;
                for(lli cant=0; cant<3; ++cant){
                    if(v[i+1][3*x+cant]>0) v[i][x]++;
                    else v[i][x]--;
                }
            }
            x/=3;
        }

        // for(lli i=n; i>=0; --i){
        //     deb(i);
        //     for(lli y: v[i]){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        if(v[0][0]>0) cout<<'A'<<endl;
        else cout<<'B'<<endl;
    }
    

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    //cin>>t;
    while(t--) solve();
}