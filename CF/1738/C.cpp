    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        lli a=0,b=0;
        for(lli i=0; i<n; ++i){
            lli x;
            cin>>x;
            if(x%2) b++;
            else a++;
        }
        if(b%4==0 || b%4==3 || (b%4==1 && a%2==1)){
            cout<<"Alice"<<endl;
        }
        else cout<<"Bob"<<endl;
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