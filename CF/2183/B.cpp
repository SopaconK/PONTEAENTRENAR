    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,k;
        cin>>n>>k;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i) cin>>v[i];
        vector<lli> used (n+1,0);
        for(lli i=0; i<n; ++i){
            if(v[i]<=n) used[v[i]]++;
        }
        lli ans=0;
        for(lli i=0; i<=n; ++i){
            if(used[i]) ans++;
            else break;
        }
        ans=min(ans, k-1);
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