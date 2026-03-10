//(n^2 2) 4(n-2)*(n-1) 
    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli k;
        cin>>k;
        for(lli i=1; i<=k; ++i){
            lli ans=1;
            ans*=(i*i);
            ans*=(i*i-1);
            ans/=2;
            ans-=(4*(i-2)*(i-1));
            cout<<ans<<endl;
        }   
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
   //     cin>>t;
        while(t--){
            solve();
        }
    }