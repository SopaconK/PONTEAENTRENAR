    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,x;
        cin>>n>>x;
        vector<lli> v (n+1,0);
        vector<lli> presum(n+1,0);
        for(lli i=1; i<=n; ++i){
            cin>>v[i];
            presum[i]=presum[i-1]+v[i];
        }
        vector<lli> ind (n+1,0);
        for(lli i=1; i<=n; ++i){
            lli y=x+presum[i-1];
            lli l=1;
            lli r=n;
            while(l<r){
                lli m=(l+r)/2;
                if(presum[m]<=y){
                    l=m+1;
                }
                else{
                    r=m;
                }
            }
       //     deb(i);
         //   deb(r)
            ind[i]=r;
        }

        vector<lli> dp(n+2,0);
        lli sum=n*(n+1)/2;
        for(lli i=n; i>=1; --i){

            dp[i]=1+dp[ind[i]+1];
            if(presum[ind[i]]-presum[i-1]<=x) dp[i]--;
            sum-=dp[i];
      //      deb(i);
        //    deb(dp[i]);
        }
        cout<<sum<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        lli t=1;
        cin>>t;
        while(t--){
            solve();
        }
    }