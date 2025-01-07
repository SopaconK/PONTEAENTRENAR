    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli x;
        cin>>x;
        lli ans=2025;
        for(lli i=1; i<=9; ++i){
            if(x%i==0){
                lli aux=x/i;
                if(aux<=9){
                    ans-=x;
                }
            }
        }
        cout<<ans<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
      //  cin>>t;
        while(t--){
            solve();
        }
    }