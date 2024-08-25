#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'

void solve(){
    lli n;
    cin>>n;
    for(lli i=0; i<n-2; ++i){
        cout<<1<<" ";
    }
    cout<<2<<" "<<n<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    while(t--){
        solve();
    }
}