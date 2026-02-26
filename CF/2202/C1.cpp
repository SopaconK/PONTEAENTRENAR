    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i) cin>>v[i];
        lli ans=1;
        lli mini=v[0]+1;
        lli maxi=v[0]+1;
        for(lli i=1; i<n; ++i){
            if(v[i]>=mini  && v[i]<=maxi){
                maxi=v[i]+1;
                continue;
            }
            ans++;
            mini=v[i]+1;
            maxi=v[i]+1;
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