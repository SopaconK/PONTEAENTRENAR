    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    const lli INF=1e18;
    
    vector<lli> val;
    vector<vector<lli>> sv;
    lli ans;
    void dfs(lli n, vector<vector<lli>> &sons, vector<lli> &values){
        lli N=sons.size()-1;
        if(sons[n].size()==0){
            for(lli i=1; i<=N; ++i){
                sv[n][i]=INF;
            }
            val[n]=values[n];
        }
        else{
            lli sum=0;
        
            for(lli x: sons[n]){
                dfs(x, sons, values);
                for(lli i=1; i<N; ++i){
                    sv[n][i+1]+=sv[x][i];
                    if(sv[n][i+1]>INF) sv[n][i+1]=INF;
                }
                sum+=val[x];
            }
            val[n]=values[n];
            if(sum<values[n]){
                lli diff=-sum+values[n];
                lli ind=2;
                while(diff>0){
                    if(sv[n][ind]>=diff){
                        ans+=(ind-1)*diff;
                        sv[n][ind]-=diff;
                        diff=0;
                    }
                    else{
                        ans+=(ind-1)*sv[n][ind];
                        diff-=sv[n][ind];
                        sv[n][ind]=0;
                    }
                    ind++;
                }
            }
            sv[n][1]=max(sum-values[n], 0ll);
        }
    }

    void solve(){
        
        ans=0;
        lli n;
        cin>>n;
        vector<vector<lli>> sons (n+1);
        vector<lli> values (n+1);
        for(lli i=1; i<=n; ++i){
            cin>>values[i];
        }
        for(lli i=2; i<=n; ++i){
            lli x;
            cin>>x;
            sons[x].pb(i);
        }
        val.clear();
        sv.clear();
        val.resize(n+1);
        sv.resize(n+1, vector<lli> (n+1));
        dfs(1,sons,values);
 /*       for(lli i=1; i<=n; ++i){
            
            for(lli j=1; j<=n; ++j){
                cout<<sv[i][j]<<" ";
            }
            cout<<endl;
            cout<<"-------------------"<<endl;
        }
   */     cout<<ans<<endl;


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