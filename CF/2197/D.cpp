    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> v (n+1);
        for(lli i=1; i<=n; ++i) cin >>v[i];
        lli sq= sqrt(n);
        lli ans=0;
        for(lli i=1; i<=sq; ++i){
            for(lli j=1; j<=n; ++j){
                lli val=(j)-i*v[j];
                if(0<val && val<=n){
                    if(v[val]==i) ans++;
                }
            }
        }

        for(lli i=1; i<=n; ++i){
            if(v[i]<=sq){
                
            }
            else{
                for(lli j=i+v[i]; j<=n; j+=v[i]){
                    if(v[i]*v[j]==(j-i)) ans++;
                }
            }
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