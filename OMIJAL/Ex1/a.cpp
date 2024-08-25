#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back


void solve(){
    lli n;
    cin>>n;
    lli s=(n*(n+1))/2;
    lli sum=0;
    lli x;
    for(lli i=0; i<n-1; ++i){
        cin>>x;
        sum+=x;
    }
    s-=sum;
    cout<<s<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    while(t--){
        solve();
    }
}