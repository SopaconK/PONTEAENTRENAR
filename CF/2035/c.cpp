    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
//    #define endl '\n'

    lli in(string &s){
        lli powt=1;
        lli ans=0;
        for(char c: s){
            if(c=='1') ans+=powt;
            powt*=2;
        }
        return ans;
    }

    void solve(){
        lli n;
        cin>>n;
        if(n%2==1){
     //       cout<<n<<endl;
            lli a=n;
            string s="";
            while(a>0){
                if(a%2){
                    s+='1';
                }
                else s+='0';
                a/=2;
            }
            vector<bool> used (n+1,0);
            vector<lli> ans;
       //     deb(s);          
            while(s.size()){
         //   deb(s);

            while(s[s.size()-1]=='0') s.pop_back();
            lli x=in(s);
            ans.pb(x);
            used[x]=true;
            if(s.size()!=1){
            x=pow(2, s.size()-1);
            ans.pb(x);
            used[x]=true;
            s.pop_back();
            }
            else{
                break;
            }
            }
            for(lli i=1; i<=n; i+=2){
                if(!used[i]){
                    ans.pb(i);
                    used[i]=true;
                    break;
                }
            }
            for(lli i=1; i<=n; i++){
                if(!used[i]){
                    ans.pb(i);
                }
            }
            reverse(ans.begin(), ans.end());
            cout<<n<<endl;
            for(lli i=0; i<n; ++i){
                cout<<ans[i]<<" ";
            }
            cout<<endl;

        }
        else{
            lli a=n;
            string s2="";
            while(a>0){
                if(a%2){
                    s2+='1';
                }
                else s2+='0';
                a/=2;
            }
            vector<bool> used (n+1,0);
            vector<lli> ans;
            ans.pb(n);
            used[n]=1;
            string s="";
            while(s.size()<s2.size()-1){
                s+='1';
            }
               while(s.size()){
         //   deb(s);

            while(s[s.size()-1]=='0') s.pop_back();
            lli x=in(s);
            ans.pb(x);
            used[x]=true;
            if(s.size()!=1){
            x=pow(2, s.size()-1);
            ans.pb(x);
            used[x]=true;
            s.pop_back();
            }
            else{
                break;
            }
            }
            for(lli i=1; i<=n; i+=2){
                if(!used[i]){
                    ans.pb(i);
                    used[i]=true;
                    break;
                }
            }
            for(lli i=1; i<=n; i++){
                if(!used[i]){
                    ans.pb(i);
                }
            }
            reverse(ans.begin(), ans.end());
            s="";
            while(s.size()<s2.size()){
                s+='1';
            }
            cout<<in(s)<<endl;
            for(lli i=0; i<n; ++i){
                cout<<ans[i]<<" ";
            }
            cout<<endl;

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