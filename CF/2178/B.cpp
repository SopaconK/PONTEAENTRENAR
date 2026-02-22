    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        string s;
        cin>>s;
        lli ans=0;
        lli n=s.size();
        if(s[0]=='u'){
            s[0]='s';
            ans++;
        }
        if(s[n-1]=='u'){
            s[n-1]='s';
            ans++;
        }
        for(lli i=1; i<n-1; ++i){
            if(s[i]=='u'){
                if(s[i+1]!='s'){
                    s[i+1]='s';
                    ans++;
                }
            }
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