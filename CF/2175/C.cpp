    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        string s,t;
        cin>>s>>t;
        vector<lli> v(35,0);
        for(lli  i=0; i<s.size(); ++i){
            v[s[i]-'a']++;
        }
        vector<lli> c (35,0);
        for(lli i=0; i<t.size(); ++i){
            c[t[i]-'a']++;
        }
        string ans="";
        lli pos=0;
        for(lli i=0; i<35; ++i){
            //  deb(i);
            //  deb(c[i]);
            //  deb(v[i]);
            if(c[i]<v[i]){
                cout<<"Impossible"<<endl;
                return;
            }
              while(pos<s.size() && s[pos]-'a'<=i){
                ans+=s[pos];
                pos++;
            }
            for(lli j=v[i]+1; j<=c[i]; ++j){
         //       deb(j);
                ans+=('a'+i);
            }
        //    deb(ans);
          
      //      deb(ans);
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