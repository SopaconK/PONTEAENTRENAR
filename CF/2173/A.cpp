    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        lli max=-1;
        lli ans=0;
        for(lli i=0; i<n; ++i){
            if(s[i]=='1'){
                max=i+k;
            }
            if(i>max) ans++;
        }
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