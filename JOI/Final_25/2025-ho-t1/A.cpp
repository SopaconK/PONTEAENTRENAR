#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
using ld=long double;
#define deb(x) cout<<#x<<": "<<x<<endl;
#define pb push_back
#define endl '\n'

void solve(){
    lli n;
    cin>>n;
    priority_queue<pair<lli,lli>> pq;
    for(lli i=0; i<2*n; ++i){
        lli x;
        cin>>x;
        pq.push({x,i});
    }
    map<lli,lli> ans;
    lli col=n;
    lli fil=n;
    while(!pq.empty()){
        lli x=pq.top().first;
        lli y=pq.top().second;

        pq.pop();
        if(y<n){
            if(y==0){
                ans[x]++;
                continue;
            }
            if(y<col){
                ans[x]+=(col-y)*(fil-1);
                col=y;
            }
            ans[x]++;
        }
        else{
            y-=n;
            if(y==0){
                continue;
            }
            if(y<fil){
                ans[x]+=(fil-y)*(col-1);
                fil=y;
            }
            ans[x]++;
        }
   
    }
    lli cant=0;
    lli cual=0;
    for(auto a: ans){
        if(a.second>cant){
            cant=a.second;
            cual=a.first;
        }
        else if(a.second==cant){
            cual=max(cual, a.first);
        }
    }
    cout<<cual<<" "<<cant<<endl;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}