    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n2,k;
        cin>>n2>>k;
        vector<lli> v2 (n2);
        for(lli i=0; i<n2; ++i) cin>>v2[i];
        vector<lli> v;
        vector<lli> p;
    
        v.pb(0);
        p.pb(-1);
        
        for(lli i=0; i<n2; ++i){
            
            if(v2[i]>v[v.size()-1]){
                v.pb(v2[i]);
                p.pb(i);
     //           cout<<v2[i]<<" ";
            }
        }
        p.pb(n2);
       // cout<<endl;
        lli n=v.size();

        vector<vector<vector<lli>>> dp (n, vector<vector<lli>> (k+1, vector<lli>(k+1,-1e18))); // dp[ cartas, altura ]
        dp[0][0][0]=0;
        vector<vector<lli>> pre (n, vector<lli> (k+1, -1e18));
        pre[0][0]=0;
        for(lli i=1; i<n; ++i){
            lli d=(p[i+1]-p[i]);
            for(lli j=0; j<=k; ++j){
                for(lli h=0; h<=v[i]; ++h){
           //         deb(dp[i-1][j][h]);
                    dp[i][j][h]=max(dp[i][j][h], dp[i-1][j][h]+d*h);
                    if(j>=h) dp[i][j][h]=max(dp[i][j][h], pre[i-1][j-h]+d*h);
         //           cout<<dp[i][j][h]<<" ";
                }
           //     cout<<endl;
                for(lli h=0; h<=v[i]; ++h){
                    pre[i][j]=max(pre[i][j], dp[i][j][h]);
                }
            }
           // cout<<"------------"<<endl;
        }
        lli ans=0;
        for(lli i=0; i<=k; ++i){
            ans=max(ans, pre[n-1][i]);
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