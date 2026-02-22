#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define endl '\n'


void solve(lli t){
    lli n,a,b;
    cin>>n>>a>>b;
    cout<<"Case #"<<t<<": ";   
    for(lli i=1; i<2*n; ++i){
        cout<<1<<" ";
    }
    cout<<b<<endl;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    cin>>t;
    for(lli i=1; i<=t; ++i) solve(i);
}