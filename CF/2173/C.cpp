    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,k;
        cin >>n>>k;
        vector<lli> v2 (n);
        for(lli i=0; i<n; ++i){
            cin>>v2[i];
        }
        sort(v2.begin(), v2.end());
        vector<lli> v ;
        v.pb(v2[0]);
        for(lli i=1; i<n; ++i){
            if(v2[i]!=v2[i-1]){
                v.pb(v2[i]);
            }
        }

        n=v.size();

        map<lli,lli> mp;
        for(lli i=0; i<n; ++i){
            mp[v[i]]=i+1;
        }
        vector<bool> used (n,0);
        vector<lli> ans;
        for(lli i=0; i<n ; ++i){
            if(used[i]) continue;
            ans.pb(v[i]);
            for(lli j=2*v[i]; j<=k; j+=v[i]){
                if(mp[j]==0){
                    cout<<-1<<endl;
                    return;
                }
                else{
                    used[mp[j]-1]=1;
                }
            }
        }
        cout<<ans.size()<<endl;
        for(lli i=0; i<ans.size(); ++i) cout<<ans[i]<<" ";
        cout<<endl;
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