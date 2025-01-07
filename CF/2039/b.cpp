    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        string s;
        cin>>s;
        lli n=s.size();
        if(n==1){
            cout<<-1<<endl;
            return;

        }
        if(n==2){
            if(s[0]==s[1]){
                cout<<s<<endl;
            }
            else{
                cout<<-1<<endl;
            }
            return;
        }
        if(n==3){
            if(s[0]==s[1]){
                cout<<s[0]<<s[1]<<endl;
                return;
            }
            if(s[1]==s[2]){
                cout<<s[1]<<s[2]<<endl;
                return;
            }
            if(s[0]!=s[2]){
                cout<<s<<endl;
                return;
            }
            cout<<-1<<endl;
            return;
        }
        bool ans=false;
        if(s[n-2]==s[n-1]){
            cout<<s[n-2]<<s[n-1]<<endl;
            return;
        }
        for(lli i=0; i<n-2; ++i){
            if(s[i]==s[i+1]){
                cout<<s[i]<<s[i+1]<<endl;
                return;
            }
            if(s[i+1]==s[i+2]){
                cout<<s[i+1]<<s[i+2]<<endl;
                return;
            }
            if(s[i]!=s[i+2]){
                cout<<s[i]<<s[i+1]<<s[i+2]<<endl;
                return;
            }
        }
        cout<<-1<<endl;
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