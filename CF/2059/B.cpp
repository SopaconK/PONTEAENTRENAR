    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,k;
        cin>>n>>k;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }
        if(n==k){
            for(lli i=0; 2*i<n; ++i){
                if(v[2*i+1]!=i+1){
                    cout<<i+1<<endl;
                    return;
                }
            }
            cout<<n/2+1<<endl;
            return;
        }
        for(lli i=1; i<=n-k+1;++i ){
            if(v[i]!=1){
                cout<<1<<endl;
                return;
            }
        }
        cout<<2<<endl;
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