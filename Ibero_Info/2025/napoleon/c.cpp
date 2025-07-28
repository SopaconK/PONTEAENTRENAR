#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define endl '\n'




void solve(){
    lli n;
    cin>>n;
    vector<lli> f (n);
    for(lli i=0; i<n; ++i) cin>>f[i];
    vector<lli> e (n);
    for(lli i=0; i<n; ++i) cin>>e[i];
    lli s;
    cin>>s;
    while(s--){
        lli k,o,i,E;
        cin>>k>>o>>i>>E;
        if(k>o){
            cout<<"NO"<<endl;
            continue;
        }
        lli cant=2^n;
        bool pos=false;
        for(lli x=0; x<cant; ++x){
            lli sa=0;
            lli si=0;
            lli se=0;

            for(lli j=0; j<n; ++j){
                if((x>>j)%2==1){
                    sa++;
                    si+=f[j];
                    se+=e[j];
                }
            }
            if(si==i && se==E && sa==k){
                cout<<"YES"<<endl;
                pos=true;
                break;
            }
        }
        if(!pos){
            cout<<"NO"<<endl;
        }
    }

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t;
    cin>>t;
    while(t--)
    solve();
}