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
        for(lli i=0; i<n; ++i) cin>>v[i];
        sort(v.begin(), v.end());
        bool pos=1;
        for(lli i=1; i<n-1; i+=2){
            if(v[i]!=v[i+1]){
                pos=0; break;
            }
        } 
        if(pos){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
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