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
        map<char, int> mp;
        for(char c: s){
            mp[c]++;
        }
        string ans="";
        while(ans.size()!=n){
            for(char c='a'; c<='z'; ++c){
                if(mp[c]>0){
                    ans+=c;
                    mp[c]--;
                }
            }
        }
       cout<<ans<<endl;
        



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