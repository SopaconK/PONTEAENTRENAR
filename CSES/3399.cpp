    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,a,b;
        cin>>n>>a>>b;
    //    deb(a);
      //  deb(b);
        if(n<a+b){
            cout<<"NO"<<endl;
            return;
        }
        if(a==0 && b==0){
            cout<<"YES"<<endl;
            for(lli i=1; i<=n; ++i){
                cout<<i<<" ";
            }
            cout<<endl;
            for(lli i=1; i<=n; ++i){
                cout<<i<<" ";
            }
            cout<<endl;
            return;
        }
        if(a==0 || b==0){
            cout<<"NO"<<endl;
            return;
        }
        cout<<"YES"<<endl;
        for(lli i=n; i>n-a; --i){
            cout<<i<<" ";
        }
        for(lli i=n-a; i>n-a-b; --i){
            cout<<i<<" ";
        }
        for(lli i=n-a-b; i>=1; --i){
            cout<<i<<" ";
        }
        cout<<endl;
        for(lli i=n-b; i>n-a-b; --i ){
            cout<<i<<" ";
        }
        for(lli i=n; i>n-b; --i){
            cout<<i<<" ";
        }
          for(lli i=n-a-b; i>=1; --i){
            cout<<i<<" ";
        }
        cout<<endl;



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