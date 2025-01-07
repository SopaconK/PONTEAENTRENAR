    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
//    #define endl '\n'
    using ld=long double;

    void solve(){
        lli n,x;
        cin>>n>>x;
        vector<lli> p(n);
        for(lli i=0; i<n; ++i) cin>>p[i];
        vector<ld> prob (n+1,0);
        prob[0]=1;
        ld ans=0;
        ld eps=.9999999;
        ld tot=0;
        lli cant=0;
        for(lli i=0; i<n; ++i){
                for(lli j=n; j>0; --j){
                
                    prob[j]=(prob[j])*((ld) (100-p[i])/100)+(prob[j-1])*((ld)p[i]/100);
                }
                prob[0]*=((ld) (100-p[i])/100);
            }
       //     for(lli i=0; i<=n; ++i) deb(prob[i]);
      
        vector<ld> dp (x+1,0);
        dp[0]=0;
        for(lli i=1; i<=x; ++i){
            dp[i]=prob[0];
            for(lli j=1; j<=n; j++){
                if(j>=i){
                    dp[i]+=prob[j];
                }
                else{
                    dp[i]+=prob[j]*(dp[i-j]+1);
                }
            }
            dp[i]/=(1-prob[0]);
      //      deb(dp[i]);
        }
        ans=dp[x];
        cout<<setprecision(10)<<ans<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
    //    cin>>t;
        while(t--){
            solve();
        }
    }