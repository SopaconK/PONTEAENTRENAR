    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    void solve(){
         lli n;
         cin>>n;
         string s;
         cin>>s;
         lli last=-1;
         lli cero=0;
         lli one=0;
         for(lli i=0; i<n; ++i){
          if(s[i]=='0'){
            if(last!=0){
              last=0;
              cero++;
            }
          }
          else{
            last=1;
            one++;
          }
         }
         if(one>cero){
          cout<<"YES"<<endl;
         }else{
          cout<<"NO"<<endl;
         }
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