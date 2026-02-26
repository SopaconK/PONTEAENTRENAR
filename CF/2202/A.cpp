    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
     lli x,y;
     cin>>x>>y;
     lli s=x+y;
     if(s%3!=0){
        cout<<"NO"<<endl;
        return;
     }
     lli k=s/3;
     if(abs(y)>k){
        cout<<"NO"<<endl;
        return;
     }
     cout<<"YES"<<endl;
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