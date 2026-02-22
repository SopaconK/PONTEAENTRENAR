    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        lli ans=0;
        for(lli i=n; i<=n+100; ++i){
            lli d=0;
            lli i2=i;
            while(i2>0){
                d+=i2%10;
                i2/=10;
            }
            if(i-d==n) ans++;
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