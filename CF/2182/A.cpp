    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        string s;
        cin>>s;
        
        bool a=0;
        bool b=0;
        for(lli i=3; i<n; ++i){
            if(s[i-3]=='2' && s[i-2]=='0' && s[i-1]=='2'){
                if(s[i]=='5'){
                    a=1;
                }
                if(s[i]=='6'){
                    b=1;
                }
            }
        }
        if(!a || b){
            cout<<0<<endl;
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