    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,d;
        cin>>n>>d;
        string s;
        cin>>s;
       reverse(s.begin(), s.end());
       for(lli i=0; i<n; ++i){
        if(d==0) break;
        if(s[i]=='@'){
            s[i]='.';
            d--;
        }
       }
       reverse(s.begin(), s.end());
       cout<<s<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
     //   cin>>t;
        while(t--){
            solve();
        }
    }