    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        if(n==1){
            cout<<1<<endl;
            return;
        }
        if(n<=3){
            cout<<"NO SOLUTION"<<endl;
            return;
        }
        for(lli i=2; i<=n; i+=2){
            cout<<i<<" ";
        }
        for(lli i=1; i<=n; i+=2){
            cout<<i<<" ";
        }
        cout<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
       // cin>>t;
        while(t--){
            solve();
        }
    }