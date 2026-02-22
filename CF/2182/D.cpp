    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    const lli MOD=998244353;

    vector<vector<lli>> bin;
    lli binom (lli n, lli m){
        while(bin.size()<=n){
            bin.pb(vector<lli> (bin.size()+1, -1));
        }
        if(n<m) return 0;
        if(bin[n][m]!=-1) return bin[n][m];
        if(m==0) return bin[n][m]=1;
        if(n==m) return bin[n][m]=1;
        lli a=binom(n-1,m);
        lli b=binom(n-1, m-1);
        return bin[n][m]=(a+b)%MOD;
    }

    lli fact(lli n){
        if(n==0) return 1ll;
        lli x=fact(n-1);
        x*=n;
        x%=MOD;
        return x;
    }

    void solve(){
        lli n;
        cin>>n;
        lli k;
        cin>>k;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i) cin>>v[i];
        sort(v.rbegin(), v.rend());
        lli x=1;
        lli aux=0;
        for(lli i=1; i<n; ++i){
            if(v[i]==v[0]) x++;
            else{
                aux+=(v[0]-1-v[i]);
            }
        }
        if(aux>k){
            cout<<0<<endl; 
            return;
        }
        k-=aux;
        lli y=n-x;
        if(k>=y){
            cout<<fact(n)<<endl;
            return;
        }
        lli ans=binom(y, k);
        ans*=fact(k+x);
        ans%=MOD;
        ans*=fact(y-k);
        ans%=MOD;
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