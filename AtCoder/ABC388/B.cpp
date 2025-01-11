    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,d;
        cin>>n>>d;
        vector<lli> t (n);
        vector<lli> l(n);
        for(lli i=0; i<n; ++i){
            cin>>t[i]>>l[i];
        }
        for(lli k=1; k<=d; ++k){
            lli ans=0;
            for(lli i=0; i<n; ++i){
                ans=max(ans, t[i]*(l[i]+k));
            }
            cout<<ans<<endl;
        }
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