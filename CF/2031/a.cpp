    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> h(n);
        map<lli,lli> mp;
        for(lli i=0; i<n; ++i){
            cin>>h[i];
            mp[h[i]]++;
        }
        lli maxi=0;
        for(lli i=0; i<n; ++i){
            maxi=max(maxi, mp[h[i]]);
        }
        lli ans=n-maxi;
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