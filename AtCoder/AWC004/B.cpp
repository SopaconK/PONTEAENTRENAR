    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,t;
        cin>>n>>t;
        lli ans=0;
        for(lli i=0; i<n; ++i){
            lli a,b;
            cin>>a>>b;
            a-=(b*t);
            a=max(a, 0ll);
            ans+=a;
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