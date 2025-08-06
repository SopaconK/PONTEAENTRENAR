    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    lli MOD=1e9+7;
    void solve(){
        lli n,k;
        cin>>n>>k;
        lli ant=0;
        lli act=1%k;
        lli ind=1;
        while(act!=0){
            swap(ant, act);
            act+=ant;
            act%=k;
            ind++;
        }
        ind%=MOD;
        n%=MOD;
        lli ans=ind*n;
        ans%=MOD;
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