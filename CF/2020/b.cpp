    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli k;
        cin>>k;
        lli x=sqrt(k);
        while(x*x-x<k){
            x++;
        }
         x--;
       
        lli dif=k-x*x+x;
        lli ans=x*x+dif;
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