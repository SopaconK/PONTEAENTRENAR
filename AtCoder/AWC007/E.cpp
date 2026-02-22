    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m;
        cin>>n>>m;
        lli s,t;
        cin>>s>>t;
        vector<lli> v (m);
        for(lli i=0; i<m; ++i) cin>>v[i];
        s--;
        t--;
        for(lli i=0; i<m; ++i) v[i]--;
        v.pb(s);
        v.pb(t);
        vector<vector<lli>> dis (m+2, vector<lli> (m+2, 0ll));
        for(lli i=0; i<m+2; ++i){
            for(lli j=0; j<m+2; ++j){
                lli x=v[i]/n;
                lli y=v[i]%n;
                lli w=v[j]/n;
                lli z=v[j]%n;
                dis[i][j]=abs(x-w)+abs(y-z);
            }
        }
        map<pair<lli,lli>, lli> mp;
        mp[{0,1}]=0;
        queue<pair<lli,lli>> q;
        q.push({0,1});
        
        for(lli i=0; i<)
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
   //     cin>>t;
        while(t--){
            solve();
        }
    }