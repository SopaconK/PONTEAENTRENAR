    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m,k;
        cin>>n>>m>>k;
        vector<vector<lli>> v (n, vector<lli> (m));
        for(lli i=0; i<n; ++i){
            for(lli j=0; j<m; ++j){
                cin>>v[i][j];
            }
        }
        vector<vector<lli>> dp (n, vector<lli> (m, 1e17));
        for(lli i=0; i<n; ++i){ //number of line
            for(lli j=0; j<m; ++j){ //number of shift
                vector<lli> ans (m, 1e17);
                for(lli x=0; x<m; ++x){
                    
                    if(x>0){
                        ans[x]=min(ans[x], ans[x-1]+v[i][(x+j)%m]);
                    }
                    if(i>0){
                        ans[x]=min(ans[x], dp[i-1][x]+v[i][(x+j)%m]);
                    }
                    if(i==0 && x==0){
                        ans[0]=v[i][(x+j)%m];
                    }
                    
                }
                for(lli x=0; x<m; ++x){
                    dp[i][x]=min(dp[i][x], ans[x]+j*k);
                }
            }

        }
        cout<<dp[n-1][m-1]<<endl;
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