    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
   // #define endl '\n'


    void solve(){
        lli n,k;
        cin>>n>>k;
        if(k==1){
            cout<<n<<endl;
            return;
        }
        lli aux=k;
        while(aux<=1e18/k){
            aux*=k;
        }
        lli ans=0;
        while(n>0){

            lli xd=n/aux;
            n-=aux*xd;
            ans+=xd;
            aux/=k;
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