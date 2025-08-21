    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    const lli MOD=1e9+7;

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

    lli inv(lli a){
        return binexp(a, MOD-2);
    }

    void solve(){
        lli n,k;
        cin>>n>>k;
        lli unos=0;
        lli ceros=0;
        for(lli i=0; i<n; ++i){
            lli x;
            cin>>x;
            if(x){
                unos++;
            }
            else ceros++;
        }
        vector<lli> a (unos+1,1);
        vector<lli> b (ceros+1,1);
        
        for(lli i=1; i<=unos; ++i){
            a[i]=a[i-1];
            a[i]*=(unos-i+1);
            a[i]%=MOD;
            a[i]*=inv(i);
            a[i]%=MOD;
        }

        for(lli i=1; i<=ceros; ++i){
            b[i]=b[i-1];
            b[i]*=(ceros-i+1);
            b[i]%=MOD;
            b[i]*=inv(i);
            b[i]%=MOD;
        }

        lli ans=0;

        
        lli ini=(k+1)/2;

        for(lli i=ini; i<=k; ++i){
            if(i>unos || k-i >ceros) continue;
            lli s=a[i]*b[k-i];
            s%=MOD;
            ans+=s;
            ans%=MOD;
    //        deb(i);
      //      deb(a[i]);
        //    deb(b[k-i]);
        }
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