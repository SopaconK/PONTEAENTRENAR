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
        vector<lli> cnt (n,0);
        lli mx=0;
        for(lli i=0; i<n; ++i){
            lli x;
            cin>>x;
            x--;
            cnt[x]++;
            mx=max(mx, cnt[x]);
        }

        vector<lli> dp (n+1,0);
        dp[0]=1;
        for(lli i=0; i<n;++i){
            for(lli j=n; j>=cnt[i]; --j){
                dp[j]+=cnt[i]*dp[j-cnt[i]];
                dp[j]%=MOD;
            }
        }
        lli ans=0;
        for(lli i=mx; i<=n; ++i) {
            ans+=dp[i];
            ans%=MOD;
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