#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define endl '\n'
#define deb(x) cout<<#x<<": "<<x<<endl;



void solve(){   
    lli k;
    cin>>k;
    lli x=pow(2,k);
    vector<lli> v (x);
    lli s=0;
    for(lli i=0; i<x; ++i){
        cin>>v[i];
        s+=v[i];
    }
    if(s<=k+1){
        cout<<-1<<endl;
        return;
    }

    for(lli i=0; i<x; ++i){
        if(v[i]==0) continue;
        for(lli j=0; j<k; ++j){
            if((i>>j)%2==0){
                lli y=i^(1<<j);
                if(v[y]==0){
         //           deb(i);
           //         deb(y);
                    cout<<-1<<endl;
                    return;
                }
            }
        }
    }
    cout<<1<<endl;
    cout<<0<<endl;

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}