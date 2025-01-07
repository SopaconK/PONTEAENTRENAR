    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    //#define endl '\n'


    void solve(){
        lli n,m;
        cin>>n>>m;
        vector<vector<lli>> values (n+m+1);
        vector<lli> v (n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
            values[v[i]].pb(0);
        }
        for(lli i=1; i<=m; ++i){
            lli p,vi;
            
            cin>>p>>vi;
            
            p--;
            values[v[p]].pb(i);
            v[p]=vi;
            values[vi].pb(i);
        }
        for(lli i=0; i<n; ++i){
            values[v[i]].pb(m+1);
        }
        lli ans=0;
        for(lli i=1; i<=n+m; ++i){
            lli x=0;
            
          
            for(lli j=0; j<values[i].size(); j+=2){
                x+=values[i][j+1]-values[i][j];
            }
            lli y=m+1-x;
            lli aux=x*y;
            lli aux2=x*(x-1);
            aux2/=2;
            aux+=aux2;
            ans+=aux;
        }
        cout<<ans<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
        cin>>t;
        while(t--){
            solve();
        }
    }