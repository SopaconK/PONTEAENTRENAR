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
     if(n%2==0){
        for(lli i=0; i<n; i+=2){
            if(s[i]==s[i+1] && s[i]!='?'){
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
        return;
     }
     if(s[0]!='a' && s[0]!='?'){
        cout<<"NO"<<endl;
        return;
     }
     for(lli i=1; i<n; i+=2){
         if(s[i]==s[i+1] && s[i]!='?'){
                cout<<"NO"<<endl;
                return;
            }
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