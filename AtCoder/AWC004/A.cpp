    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,s,t;
        cin>>n>>s>>t;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i) cin >>v[i];
        lli x=s*60;
        for(lli i=0; i<n; ++i) x+=v[i];
        if(x<=t*60){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
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