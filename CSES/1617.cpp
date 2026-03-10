    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    lli MOD=1e9+7;

    lli binexp(lli b, lli p){
        if(p==0) return 1ll;
        if(p==1) return b%MOD;
        lli x=binexp(b, p/2);
        x*=x;
        x%=MOD;
        if(p%2){
            x*=b;
            x%=MOD;
        }
        return x;
    }


    void solve(){
        lli n;
        cin>>n;
        cout<<binexp(2, n)<<endl;
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