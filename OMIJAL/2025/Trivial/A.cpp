#include<bits/stdc++.h>
using namespace std;
using lli=long long int;

void solve(){
   lli n;
   cin>>n;
    if(n==1){
        cout<<"No"<<endl;
        return;
    }
   for(lli i=2; i*i<=n; ++i){
    if(n%i==0){
        cout<<"No"<<endl;
        return;
    }
   }
   cout<<"Si"<<endl;
}


int main(){
    solve();
}