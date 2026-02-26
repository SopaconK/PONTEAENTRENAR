    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    const lli MOD=1e9+7;
    vector<pair<lli,lli>> fib;

    void precalc(){
        fib.resize(1e6+5);
        fib[0]={0,0};
        fib[1]={1,0};
        fib[2]={0,1};
        for(lli i=3; i<fib.size(); ++i){
            fib[i]={fib[i-1].first+fib[i-2].first, fib[i-1].second+fib[i-2].second};
            fib[i].first%=MOD;
            fib[i].second%=MOD;
        }
    }
    void solve(){
     lli a,b,p;
     cin>>a>>b>>p;
  //   deb(fib.size());
     lli ans=a*fib[p].first;
     ans%=MOD;
     ans+=b*fib[p].second;
     ans%=MOD;
     cout<<ans<<endl;   
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        precalc();
        int t=1;
        cin>>t;
        while(t--){
            solve();
        }
    }