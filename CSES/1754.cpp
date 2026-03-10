    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli a,b;
        cin>>a>>b;
        if((a+b)%3!=0){
            cout<<"NO"<<endl;
            return;
        }
        lli s=(a+b)/3;
        lli d=(a-b);

        if((s+d)>=0 && (s+d)%2==0 && (s-d)>=0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
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