#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'

void solve(){
    lli n;
    cin>>n;
    string s;
    cin>>s;
    lli q;
    cin>>q;
    lli val=0;
    while(q--){
        char c;
        cin>>c;
        lli x;
        cin>>x;
        if(c=='L') val+=x;
        else val-=x;
        val%=n;
    }
    val+=n;
    val%=n;
    for(lli i=val; i<n; ++i){
        cout<<s[i];
    }
    for(lli i=0; i<val; ++i){
        cout<<s[i];
    }
    cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    while(t--){
        solve();
    }
}