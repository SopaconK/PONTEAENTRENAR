    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> a (n);
        vector<lli> b (n);
        vector<lli> c (n);
        for(lli i=0; i<n;++i) cin>>a[i];
        for(lli i=0; i<n;++i) cin>>b[i];
        for(lli i=0; i<n;++i) cin>>c[i];
        
        vector<bool> x (n,1);
        vector<bool> y(n,1);
        for(lli i=0; i<n; ++i){
            for(lli j=0; j<n; ++j){
                if(a[i]>=b[j]){
                    x[(i-j+n+n)%n]=0;
                }
                if(b[i]>=c[j]){
                    y[(i-j+n+n)%n]=0;
                }
            }
        }
        lli w=0;
        lli z=0;
        for(bool i: x){
            if(i) w++;
        }
        for(bool i:y){
            if(i) z++;
        }
        cout<<w*z*n<<endl;
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