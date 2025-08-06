    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> v2 (n);
        for(lli i=0; i<n; ++i){
            cin>>v2[i];
        }
        sort(v2.rbegin(), v2.rend());
        vector<lli> v;
        v.pb(v2[0]);
        for(lli i=1; i<n; ++i){
            if(v2[i]!=v2[i-1]) v.pb(v2[i]);
        }
        n=v.size();
  //      deb(n);
        lli last=-1;
        for(lli i=0; i<n-1; ++i){
            v[i]-=v[i+1];
    //        deb(v[i]);
            if(v[i]>1) last=i;
        }
        if(v[n-1]>1) last=n-1;
        
        lli ans=n-last;
        if(last==-1) ans=n;
      //  deb(ans);
        ans%=2;
        if(ans==1){
            cout<<"Alice"<<endl;
        }
        else cout<<"Bob"<<endl;


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