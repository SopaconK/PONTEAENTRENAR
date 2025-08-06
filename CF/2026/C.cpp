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
        lli ans=(n*(n+1))/2;
        lli rest=n;
        lli pend=0;
        for(lli i=n-1; i>=0; --i){
            if(s[i]=='1'){
                if(rest>1){
                    ans-=(i+1);
                    rest-=2;
                    pend++;
                }
            }
            else{
                if(pend>0){
                    pend--;
                }
                else{
                    rest--;
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