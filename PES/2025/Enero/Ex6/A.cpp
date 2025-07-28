    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    using ld=long double;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,h;
        cin>>n>>h;
        for(lli i=1; i<n; ++i){
            ld ans=(ld)h*sqrt((ld) i/n);
            cout<<setprecision(12)<<ans<<" ";
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