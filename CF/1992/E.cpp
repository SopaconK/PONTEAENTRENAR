    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        string s;
        cin>>s;
        lli n=0;
        lli x=s.size();
        for(char c:s){
            n*=10;
            n+=c-'0';
        }
        vector<pair<lli,lli>> ans;
        string s2="";
        for(lli a=1;   a<=10000; ++a){
            s2+=s;
            
            lli v=0;
            
            for(lli ind=0; ind<s2.size(); ++ind){
                lli b=s2.size()-ind-1;
                v*=10;
                v+=s2[ind]-'0';
                lli eq=n*a-b;

                if(v>eq){
                    break;
                }
                if(b>10000) continue;
                if(b<=0) break;
                if(eq==v){
                    ans.pb({a,b});
                    break;
                }
            }
        }
        cout<<ans.size()<<endl;
        for(auto a: ans){
            cout<<a.first<<" "<<a.second<<endl;
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