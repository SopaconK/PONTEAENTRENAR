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
        for(lli i=0; i<n-1; ++i){
            if(v[i+1]<2*v[i] && v[i]<2*v[i+1]){
                cout<<"YES"<<endl;
                return;
            }
        }
        cout<<"NO"<<endl;
        return;
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