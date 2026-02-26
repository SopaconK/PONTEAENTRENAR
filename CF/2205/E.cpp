    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    const lli MOD=998244353;

    void solve(){
        lli n;
        cin>>n;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i) cin>>v[i];
        vector<lli> powtwo (n+1,1);
        powtwo[2]=2;
        for(lli i=3; i<=n; ++i){
            powtwo[i]=powtwo[i-1]*2;
            powtwo[i]%=MOD;
        }
        map<vector<lli>, lli> mp;
        vector<lli> aux (8007, 0);
        lli ans=0;
        for(lli i=0; i<n; ++i){
            for(lli j=i; j>=0; --j){
                vector<lli> v2;
                for(lli x=j; x<=i; ++x) v2.pb(v[x]);
            
                ans+=(mp[v2]*powtwo[n-1-i])%MOD;
                ans%=MOD;
                mp[v2]+=powtwo[i];
                mp[v2]%=MOD;
            }

        }
        lli anss=powtwo[n];
        anss-=ans;
        ans=anss;
        ans%=MOD;
        ans+=MOD;
        ans%=MOD;
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