    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    using ld=long double;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }
        ld val=(ld) v[1]/v[0];
        for(lli i=1; i<n-1; ++i){
            ld a=(ld)v[i+1]/v[i];
            if(a!=val){
                cout<<"No"<<endl;
                return;
            }
        }
        cout<<"Yes"<<endl;
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