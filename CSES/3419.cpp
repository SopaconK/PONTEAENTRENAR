    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<vector<lli>> ans (n, vector<lli> (n));
        vector<vector<bool>> used (n, vector<bool> (2*n, 0));
        for(lli i=0; i<n; ++i){
            vector<bool> v (2*n, 0);
            for(lli j=0; j<n; ++j){
                lli ind=0;
                while(used[j][ind] || v[ind]){
                    ind++;
                }
                ans[i][j]=ind;
                used[j][ind]=1;
                v[ind]=1;
            }
        }
        for(lli i=0; i<n; ++i){
            for(lli j=0; j<n; ++j){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
       // cin>>t;
        while(t--){
            solve();
        }
    }   