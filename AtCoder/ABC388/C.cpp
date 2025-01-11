    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> v(n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }
        lli ans=0;
        lli p=0;
        for(lli i=0; i<n; ++i){
            while(p<n && v[p]<2*v[i]){
                p++;
            }
            ans+=n-p;
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