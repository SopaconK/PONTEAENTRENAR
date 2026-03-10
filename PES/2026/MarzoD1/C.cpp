#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define endl '\n'


vector<lli> parent;

lli par(lli x){
    if(parent[x]==x) return x;
    return parent[x]=par(parent[x]);
}

lli unir(lli a, lli b, lli d){
    a=par(a);
    b=par(b);
    if(a==b) return -1ll;
    parent[a]=b;
    return d;
}


void solve(){
    lli h,w,n;
    cin>>h>>w>>n;
    vector<vector<pair<lli,lli>>>v  (w);
    for(lli i=0; i<n; ++i){
        lli r,c;
        cin>>r>>c;
        r--;
        c--;
        v[c].pb({r, i});
    }
    for(lli i=0; i<w; ++i) sort(v[i].begin(), v[i].end());
    vector<pair<lli, pair<lli,lli>>> aristas;
    lli low=w;
    lli big=-1;
    for(lli i=0; i<w; ++i){
        if(v[i].size()>0){
            low=min(low, i);
            big=max(big, i);
        }
    }
    for(lli i=low; i<=big; ++i){
        if(v[i].size()==0){
            cout<<-1<<endl;
            return;
        }
    }
    
    for(lli i=low; i<=big; ++i){
        lli ind1=0;
        lli ind2=0;
        for(lli j=0; j<v[i].size(); ++j){
            // if(i>low){
            //     while(ind1<v[i-1].size() && v[i-1][ind1].first < v[i][j].first) ind1++;
            //     if(ind1<v[i-1].size()){
            //         aristas.pb({abs(v[i-1][ind1].first-v[i][j].first),{v[i-1][ind1].second, v[i][j].second}});
            //     }
            //     if(ind1>0){
            //         aristas.pb({abs(v[i-1][ind1-1].first-v[i][j].first),{v[i-1][ind1-1].second, v[i][j].second}});
            //     }
            // }
            if(i<big){
                 while(ind2<v[i+1].size() && v[i+1][ind2].first < v[i][j].first) ind2++;
                 if(ind2<v[i+1].size()){
                    aristas.pb({abs(v[i+1][ind2].first-v[i][j].first),{v[i+1][ind2].second, v[i][j].second}});
                }
                if(ind2>0){
                   aristas.pb({abs(v[i+1][ind2-1].first-v[i][j].first),{v[i+1][ind2-1].second, v[i][j].second}});
                }
            }

            if(j>0){
                aristas.pb({abs(v[i][j].first-v[i][j-1].first-1),{v[i][j].second, v[i][j-1].second}});
            }
            
        }
    }
    sort(aristas.begin(), aristas.end());
    // for(auto a: aristas){
    //     cout<<a.first<<" ("<<a.second.first<<" "<<a.second.second<<")"<<endl;
    // }
    lli ans=-1;
    parent.resize(n);
    for(lli i=0; i<n; ++i){
        parent[i]=i;
    }
    for(auto a: aristas){
        ans=max(ans, unir(a.second.first, a.second.second, a.first));
    }
    cout<<ans<<endl;


}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    //cin>>t;
    while(t--) solve();
}