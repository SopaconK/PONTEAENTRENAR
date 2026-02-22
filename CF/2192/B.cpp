    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> a;
        vector<lli> b;
        string s;
        cin>>s;
        for(lli i=1; i<=n; ++i){
            if(s[i-1]=='1'){
                a.pb(i);
            }
            else b.pb(i);
        }

        if(a.size()%2==0){
            cout<<a.size()<<endl;
            for(lli x: a){
                cout<<x<<" ";
            }
            if(a.size()>0)
            cout<<endl;
            return;
        }
        if(b.size()%2==1){
            cout<<b.size()<<endl;
            for(lli x: b){
                cout<<x<<" ";
            }
            if(b.size()>0)
            cout<<endl;
            return;
        }
        cout<<-1<<endl;
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