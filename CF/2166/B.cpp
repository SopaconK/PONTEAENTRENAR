    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli a,b,n;
        cin>>a>>b>>n;
        if(a!=b){
            if(a<b*n) cout<<2<<endl;
            else cout<<1<<endl;
        }
        else{
            cout<<1<<endl;
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