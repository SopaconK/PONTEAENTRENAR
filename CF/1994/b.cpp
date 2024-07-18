    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        bool ans=1;
        for(lli i=0; i<n; ++i){
            if(s[i]=='1') break;
            if(t[i]=='1'){
                ans=0;
                break;
            }
        }
        if(ans){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        lli t=1;
        cin>>t;
        while(t--){
            solve();
        }
    }