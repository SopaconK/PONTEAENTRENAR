    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    using ld=long double;
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
        vector<lli> a (n);
        for(lli i=0; i<n; ++i){
            cin>>a[i];
        }
        vector<lli> p (n);
        vector<lli> np(n);
        lli inv= binexp(10000, MOD-2);
        deb(inv);
        for(lli i=0; i<n; ++i){
           cin>>p[i];
           np[i]=10000-p[i];
           np[i]*=inv;
           p[i]*=inv;
           np[i]%=MOD;
           p[i]%=MOD;
           deb(p[i]);
           deb(np[i]);
        }
      vector<lli> si(10,0);
      vector<lli> no(10, 1);
        for(lli i=0; i<n; ++i){
            for(lli j=0; j<10; ++j){
                if((a[i]>>j) & 1){
                   lli x=no[j]*p[i]+si[j]*np[i];
                    x%=MOD;
                    lli y=no[j]*np[i]+si[j]*p[i];
                    y%=MOD;
                    si[j]=x;
                    no[j]=y;
                }
                deb(i);
                deb(j);
                deb(si[j]);
                deb(no[j]);
            }
        }
        lli ans=0;
        for(lli i=0; i<1023; ++i){
            lli prob=1;
            for(lli j=0; j<10; ++j){
                if((i>>j) & 1){
                   prob*=si[j];
                }
                else{
                   prob*=no[j];
                }
                prob%=MOD;
            }
            deb(i);
            deb(prob);
            lli val=i*i;
            val%=MOD;
            val*=prob;
            val%=MOD;
            ans+=val;
            ans%=MOD;
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