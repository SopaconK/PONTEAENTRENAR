    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        string s;
        cin>>s;
        lli ans=1;
        lli act=0;
        char ant='W';
        for(char c: s){
            if(c==ant){
                act++;
                ans=max(ans, act);
            }
            else{
                act=1;
                ant=c;
            }
        }
        cout<<ans<<endl;
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