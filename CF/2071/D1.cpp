    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    vector<lli> v;
    vector<lli> prec;
    lli ans (lli x){
        if(x<v.size()) return v[x];
        lli m=x/2;
        if(m<prec.size()){
            return prec[m];
        }
        if(m%2==1){
            return prec[prec.size()-1];
        }
        return prec[prec.size()-1]^ans(m);
    }

    void solve(){
        lli n;
        cin>>n;
        lli l,r;
        cin>>l>>r;
        v.resize(n+1);
        v[0]=0;
        for(lli i=1; i<=n; ++i) cin>>v[i];
        if((n+1)%2==1){
            lli val=0;
            lli m=(n+1)/2;
            for(lli j=1; j<=m; ++j){
                val^=v[j];
            }
            v.pb(val);
        }
        prec.resize(v.size());
        prec[0]=v[0];
        for(lli i=1; i<prec.size(); ++i){
            prec[i]=prec[i-1]^v[i];
        }
        cout<<ans(l)<<endl;

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