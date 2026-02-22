    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m;
        cin>>n>>m;
        vector<vector<lli>> v (n, vector<lli> (m));
        for(lli i=0; i<n; ++i){
            for(lli j=0; j<m; ++j){
                cin>>v[i][j];
            }
        }
        vector<vector<lli>> v1 (n, vector<lli> (m, 0));
        vector<vector<lli>> v2 (n, vector<lli> (m, 0));
        v1[0][0]=v[0][0];
        for(lli i=1; i<m; ++i){
            v1[0][i]=v1[0][i-1]+v[0][i];
        }
        for(lli i=1; i<n; ++i){
            v1[i][0]=v1[i-1][0]+v[i][0];
        }
        v2[0][0]=-v[0][0];
        for(lli i=1; i<m; ++i){
            v2[0][i]=min(v2[0][i-1]+v[0][i], v1[0][i-1]-v[0][i]);
        }
        for(lli i=1; i<n; ++i){
            v2[i][0]=min(v2[i-1][0]+v[i][0], v1[i-1][0]-v[i][0]);
        }
        for(lli i=1; i<n; ++i){
            for(lli j=1; j<m; ++j){
                v1[i][j]=max(v1[i-1][j], v1[i][j-1])+v[i][j];
                v2[i][j]=min(max(v2[i-1][j], v2[i][j-1])+v[i][j], v1[i][j]-2*v[i][j]);
            }
        }
        for(lli i=0; i<n; ++i){
            for(lli j=0; j<m; ++j){
                cout<<v1[i][j]<<" ";
            }
            cout<<endl;
            
        }
        cout<<endl<<endl;
         for(lli i=0; i<n; ++i){
            for(lli j=0; j<m; ++j){
                cout<<v2[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<v2[n-1][m-1]<<endl;
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