    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m;
        cin>>n>>m;
        if(n==1 && m==1){
            cin>>n;
            cout<<-1<<endl;
            return;
        }
        vector<vector<lli>> v (n, vector<lli> (m));
        for(lli i=0; i<n; ++i){
            for(lli j=0; j<m; ++j){
                cin>>v[(i+1)%n][(j+1)%m];
            }
        } 
        for(lli i=0; i<n; ++i){
            for(lli j=0; j<m; ++j){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        } 

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