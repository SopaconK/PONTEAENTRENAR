    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
 //   #define endl '\n'

    const lli MOD=200;

    void printans(vector<lli> a, vector<lli> b){
        cout<<"Yes"<<endl;
        cout<<a.size()<<" ";
        for(lli x: a){
            cout<<x+1<<" ";
        }
        cout<<endl;
        cout<<b.size()<<" ";
        for(lli x: b){
            cout<<x+1<<" ";
        }
        cout<<endl;
    }

    void solve(){
        lli n;
        cin>>n;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i) cin>>v[i];
        vector<vector<lli>> dp(MOD);
        for(lli i=0; i<n; ++i){
            
            v[i]%=MOD;
            vector<vector<lli>> aux (MOD);
            aux[v[i]].pb(i);
            for(lli j=0; j<MOD; ++j){
                if(dp[j].size()>0){
                    if(aux[(j+v[i])%MOD].size()>0){
                        dp[j].pb(i);
                        printans(dp[j], aux[(j+v[i])%MOD]);
                        return;
                    }
                    aux[(j+v[i])%MOD]=dp[j];
                    aux[(j+v[i])%MOD].pb(i);
                }
            }
            for(lli j=0; j<MOD; ++j){
                if(aux[j].size()>0){
                    if(dp[j].size()>0){
                        printans(aux[j], dp[j]);
                        return;
                    }
                    dp[j]=aux[j];
                }
            }
        }
        cout<<"No"<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
     //   cin>>t;
        while(t--){
            solve();
        }
    }