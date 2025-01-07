    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    vector<vector<lli>> ans;
    vector<lli> act;
    void xd(lli x,lli ant,lli n, lli m){
        if(x>n) return;
        lli max=m-10*(n-x);
        for(lli i=ant+10; i<=max; ++i){
            act.pb(i);
            if(x==n){
                ans.pb(act);
            }
            else xd(x+1, i, n, m);
            act.pop_back();
        }
    }
    
    void solve(){
        lli n,m;
        cin>>n>>m;
        xd(1,-9, n,m);
        cout<<ans.size()<<endl;
        for(lli i=0; i<ans.size(); ++i){
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
    //    cin>>t;
        while(t--){
            solve();
        }
    }