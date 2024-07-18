    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    using ld=long double;

    
    vector<vector<ld>> dp;

    ld pre (lli n, lli k){
        if(n==0) return dp[n][k]=0;
        if(k==0) return dp[n][k]=0;
        if(dp[n][k]!=-1) return dp[n][k];
        ld ans=0;

        for(lli i=0; i<=n; ++i){
            ans=max(ans,(ld) i / (ld) n +pre(n-i,k-1));
        }

        return dp[n][k]=ans;
    }
    void solve(){
        lli N,K;
        cin>>N>>K;
        dp.resize(N+1, vector<ld> (K+1,-1));
        ld ans=pre(N,K);

        cout<<setprecision(10) <<ans <<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        lli t=1;
     //   cin>>t;
        while(t--){
            solve();
        }
    }