#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define endl '\n'
#define deb(x) cout<<#x<<": "<<x<<endl;

vector<lli> parent;
vector<lli> sz;

lli par(lli x){
    if(parent[x]==x) return x;
    return parent[x]=par(parent[x]);
}

void unir(lli a , lli b){
    a=par(a);
    b=par(b);
    if(a==b) return;

    parent[a]=b;
    sz[b]+=sz[a];
}


void solve(lli t){
    lli n;
    cin>>n;
    lli ans=0;
   vector<lli> v (n+1);
   for(lli i=1; i<=n; ++i){
    cin>>v[i];
   }
   parent.resize(n+1);
   sz.resize(n+1);
   for(lli i=0; i<=n; ++i){
    parent[i]=i;
    sz[i]=1;
   }

   priority_queue<pair<lli,pair<lli,lli>>, vector<pair<lli,pair<lli,lli>>>, greater<pair<lli,pair<lli,lli>>>> pq;
   for(lli i=1; i<=n; ++i){
    pq.push({v[i], {0, i}});
   }
   for(lli i=2; i<=n; ++i){
    pq.push({abs(v[i]-v[i-1]), {i, i-1}});
   }

   while(!pq.empty()){
    ans=max(ans, pq.top().first);
    lli x=pq.top().second.first;
    lli y=pq.top().second.second;

    pq.pop();

    unir(x,y);
   
    if(sz[par(y)]>=n+1) break;
   }





    cout<<"Case #"<<t<<": "<<ans<<endl;   
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    cin>>t;
    for(lli i=1; i<=t; ++i) solve(i);
}