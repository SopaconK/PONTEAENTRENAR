    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        lli n2=n;
        lli ans=1;
        for(lli i=2; i*i<=2e9+7; ++i){
            lli cont=0;
            while(n%i==0){
                cont++;
                n/=i;
            }
            while(cont>0){
                ans*=i;
                cont-=n2;
            }
        }
        if(n>1){
            ans*=n;
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