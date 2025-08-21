    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m;
        cin>>n>>m;
        lli ans=0;
        vector<vector<lli>>v (m, vector<lli> (n));
        for(lli i=0; i<n; ++i){
            for(lli j=0; j<m; ++j){
                cin>>v[j][i];
            }
        }
        for(lli i=0; i<m; ++i){
            sort(v[i].begin(), v[i].end());
            for(lli j=0; j<n-1; ++j){
                lli d=v[i][j+1]-v[i][j];
                lli t=(j+1)*(n-j-1);
            
                ans+=d*t;
            }
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