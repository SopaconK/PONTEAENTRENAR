#include<bits/stdc++.h>
using namespace std;
#define pb push_back
using lli=long long int;
#define deb(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'


void solve(){
    lli n;
    cin>>n;
    vector<lli> v(n*n, 0);
    lli sz=pow(2,n*n);
    for(lli bmk=0; bmk<sz; ++bmk){
        lli aux=bmk;
        lli cont=0;
        vector<lli> f (n,0);
        vector<lli> c (n,0);
        lli val=0;
        while(aux>0){
            if(aux%2){
                f[cont%n]++;
                c[cont/n]++;
                val++;
            }
            cont++;
            aux/=2;
        }
        bool pos=true;
        for(lli i=0; i<n; ++i){
            if(f[i]==0 || c[i]==0) pos=false;
        }
        if(pos){
            v[n*n-val]++;
        }
    }
    for(lli x: v){
        cout<<x<<endl;
    }

}




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
 //   cin>>t;
    while(t--){
        solve();
    }
}