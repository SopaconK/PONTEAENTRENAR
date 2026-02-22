    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        string s;
        cin>>s;
        bool ans=1;
        lli y=0;
        for(lli i=0; i<s.size(); ++i){
            if(s[i]=='Y') y++;
        }
        if(y>=2){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
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