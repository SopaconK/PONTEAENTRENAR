    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m;
        cin>>n>>m;
        vector<pair<lli,lli>> v (n);
        for(lli i=0; i<n; ++i){
            cin>>v[i].first;
            v[i].second=i+1;
        }
        sort(v.begin(), v.end());
        if(m>n/2){
            cout<<-1<<endl;
            return;
        }
        if(m==0){
            lli s=0;
            lli ind;
            for(lli i=n-2; i>=0; --i){
                s+=v[i].first;
                ind=i;
                if(s>=v[n-1].first) break;
                ind=-1;
            }
            if(ind==-1){
                cout<<-1<<endl;
                return;
            }
            vector<pair<lli,lli>> ans;
            for(lli i=0; i<ind; ++i){
                ans.pb({i, i+1});
            }
            for(lli j=ind; j<n-1; ++j){
                ans.pb({j,n-1});
            }
            cout<<ans.size()<<endl;
            for(lli i=0; i<ans.size(); ++i){
                cout<<v[ans[i].first].second<<" "<<v[ans[i].second].second<<endl;
            }

        }
        else{
            vector<pair<lli,lli>> ans;
            for(lli i=0; i<n-2*m; ++i){
                ans.pb({v[i].second, v[i+1].second});
            }
            for(lli i=n-1; i>=n-m; --i){
                ans.pb({v[i].second, v[i-m].second});
            }
            cout<<ans.size()<<endl;
            for(lli i=0; i<ans.size(); ++i){
                cout<<ans[i].first<<" "<<ans[i].second<<endl;
            }
        }
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