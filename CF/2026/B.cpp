    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }
        if(n%2){
            lli ans=1e18;
            for(lli i=0; i<n; i+=2){
                lli aux=1;
                for(lli j=0; j<i; j+=2){
                    aux=max(aux,v[j+1]-v[j]);
                }
                for(lli j=i+1; j<n-1; j+=2){
                    aux=max(aux, v[j+1]-v[j]);
                }
                ans=min(ans, aux);
            }
            cout<<ans<<endl;
        }
        else{
            lli ans=0;
            for(lli i=0; i<n; i+=2){
                ans=max(ans, v[i+1]-v[i]);
            }
            cout<<ans<<endl;
        }

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