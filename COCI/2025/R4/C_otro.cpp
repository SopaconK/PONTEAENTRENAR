    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> v (1024,0);
        for(lli i=0; i<n; ++i){
            lli x;
            cin>>x;
            v[x]++;
        }
        lli ans=0;
        for(lli i=0; i<1024; ++i){
            for(lli j=i; j<1024; ++j){
                if(i==j){
                    lli cant=v[i]*v[i]-v[i];
                    cant/=2;
                    cant+=v[i];
                    if(cant%2){
                   // deb(i+j);
                    ans=ans^(i+j);
                }
                }
                else{
                lli cant=v[i]*v[j];
                if(cant%2){
                    //deb(i+j);
                    ans=ans^(i+j);
                }
                }
            }
        }
        cout<<ans<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
  //      cin>>t;
        while(t--){
            solve();
        }
    }