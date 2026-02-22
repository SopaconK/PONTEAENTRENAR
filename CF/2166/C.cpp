    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }

        vector<pair<lli,lli>> p (n);
        for(lli i=0; i<n; ++i) p[i]={v[i], i};
        vector<lli> ant (n);
        vector<lli> nxt (n);
        for(lli i=0; i<n; ++i){
            ant[i]=(i-1+n)%n;
            nxt[i]=(i+1+n)%n;
        }
        sort(p.begin(), p.end());
        lli ans=0;
        for(lli i=0; i<n-1; ++i){
            lli x=p[i].second;
        
            ans+=min(v[ant[x]], v[nxt[x]]);
       
            lli u=ant[x];
            lli v=nxt[x];
            ant[v]=u;
            nxt[u]=v;
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