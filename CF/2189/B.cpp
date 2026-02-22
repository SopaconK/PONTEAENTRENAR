    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,x;
        cin>>n>>x;
        lli s=0;
        lli val=0;
        for(lli i=0; i<n; ++i){
            lli a,b,c;
            cin>>a>>b>>c;
            val=max(val, a*b-c);
            s+=max(0ll, a*(b-1));
        }
     //   deb(val);
       // deb(s);
        if(s>=x){
            cout<<0<<endl;
            return;
        }
        if(val==0){
            cout<<-1<<endl;
            return;
        }
        
        lli ans=(x-s+val-1)/val;
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