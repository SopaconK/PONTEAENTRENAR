    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    void fin(lli n, lli c){
        vector<lli> v;
        if(n==0) return;
        if(n==1){
            v.pb(1);
            v.pb(1);
        }
        else{
        v.pb(1);
        v.pb(2);
        for(lli i=3; i<=n; ++i){
            v.pb(i);
            v.pb(i-2);
        }
        v.pb(n-1);
        v.pb(n);
        }
        for(lli x: v){
            cout<<x+c<<" ";
        }
    }

    void solve(){
        lli n,k;
        cin>>n>>k;
        if(k<n || k>=2*n){
            cout<<"NO"<<endl;
            return;
        }
        cout<<"YES"<<endl;
        lli c=0;
        while(k<2*n-1){
            c++;
            cout<<c<<" "<<c<<" ";
            n--;
            k--;
        }
        fin(n, c);
        cout<<endl;
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