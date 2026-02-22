    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli p,q;
        cin>>p>>q;
        lli a=3*p;
        lli b=2*q;
        if(a==b){
            cout<<"Bob"<<endl;
            return;
        }
        if(a<b){
            cout<<"Alice"<<endl;
            return;
        }
        if(a-b <=q-1){
            cout<<"Bob"<<endl;
            return;
        }
        cout<<"Alice"<<endl;
        return;
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