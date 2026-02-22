    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,k;
        cin>>n>>k;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i) cin>>v[i];
        map<lli, lli> mp;
        mp[0]=1;
        lli ans=0;
        lli s=0;
        for(lli i=0; i<n; ++i){
            s+=v[i];
            ans+=mp[s-k];
            mp[s]++;
        }
        cout<<ans<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
  //      cin>>t;
        while(t--){
            solve();
        }
    }