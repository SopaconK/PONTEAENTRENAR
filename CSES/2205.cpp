    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void gray(lli n, vector<string> & v){
        if(n==1){
            v={"0", "1"};
            return;
        }
        gray(n-1, v);
        lli sz=v.size();
        for(lli i=sz-1; i>=0; --i){
            v.pb(v[i]);
        }
        for(lli i=0; i<sz; ++i){
            v[i]+='0';
            v[i+sz]+='1';
        }
    }

    void solve(){
        lli n;
        cin>>n;
        vector<string> ans;
        gray(n, ans);
        for(string s: ans){
            cout<<s<<endl;
        }
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
      //  cin>>t;
        while(t--){
            solve();
        }
    }