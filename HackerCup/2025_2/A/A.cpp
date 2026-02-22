#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define endl '\n'
#define deb(x) cout<<#x<<": "<<x<<endl;

void solve(lli t){
    lli n,m;
    cin>>n>>m;
    bool ans=false;
    if(n<m) ans=false;
    else{
        if(n<=2*m-2) ans=true;
        else{
            if(n%2==0) ans=true;
            else ans=false;
        }
    }
    string s;
    if(ans) s="YES";
    else s="NO";
    cout<<"Case #"<<t<<": "<<s<<endl;   
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    cin>>t;
    for(lli i=1; i<=t; ++i) solve(i);
}