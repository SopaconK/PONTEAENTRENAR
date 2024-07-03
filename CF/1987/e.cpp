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
        if(sons[n].size()==0){
            for(lli i=1; i<sons.size(); ++i){
                sv[n][i]=INF;
            }
            val[n]=values[n];
        }
        else{
            lli sum=0;
            vector<lli> aux (n+1,0);
            for(lli x: sons[n]){
                dfs(x, sons, values);
                for(lli i=1; i<=n; ++i){
                    aux[i]+=sv[x][i];
                    if(aux[i]>INF) aux[i]=INF;
                }
                sum+=val[x];
            }
            val[n]=values[n];
            if(sum<values[n]){
                lli diff=-sum+values[n];
                lli ind=1;
                while(diff>0){
                    if(aux[ind]>=diff){
                        ans+=ind*diff;
                        aux[ind]-=diff;
                        diff=0;
                    }
                    else{
                        ans+=ind*aux[ind];
                        diff-=aux[ind];
                        aux[ind]=0;
                    }
                }
            }
            sv[n][1]=max(values[n]-sum, 0ll);
            for(lli i=2; i<=n; ++i){
                sv[n][i]=aux[i-1];
            }
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