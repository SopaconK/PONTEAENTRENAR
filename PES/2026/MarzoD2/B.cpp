#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define deb(x) cout<<#x<<": "<<x<<endl;
#define pb push_back
#define endl '\n'

void solve(){
    lli n;
    cin>>n;
    vector<lli> v (n);
    lli s=0;
    for(lli i=0; i<n; ++i){
        cin>>v[i];
        s+=v[i];
    }
    stack<lli> sk;
    sk.push(s);
    lli pos=0;
    while(pos<n){
        lli x=sk.top();
        sk.pop();
        if(x==v[pos]){
            pos++;
            continue;
        }
        if(x<v[pos]){
            break;
        }
        lli y=x/2;
        x-=y;
        sk.push(y);
        sk.push(x);
    }
    if(pos<n){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Si"<<endl;
    }

   
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    //cin>>t;
    while(t--) solve();
}