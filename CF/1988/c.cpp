    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
  //  #define endl '\n'

    string s="";


    lli next (lli act){
    //  deb(act);
      if(act==-1){
        string s2="";
        lli cant=0;
        for(lli i=0; i<s.size(); ++i){
          if(s[i]=='0'){
            s2+="0";
          }
          else{
            if(cant==0){
              s2+="0";
              cant++;
            }
            else{
              s2+="1";
              cant++;
            }
          }
        }
        if(cant==1){
          for(lli i=0; i<s.size(); ++i){
            if(s[i]=='1'){
              s2[i]='1';
            }
          }
        }
        lli val=0;
        lli pow2=1;
        for(lli i=s2.size()-1; i>=0; --i){
          if(s2[i]=='1') val+=pow2;
          pow2*=2;
        }
        return val;
      }
      
      string s2="";
      lli aux=act;
      while(aux>0){
        if(aux%2) s2+="1";
        else s2+="0";
        aux/=2;
      }
      while(s2.size()<s.size()){
        s2+="0";
      }
      reverse(s2.begin(), s2.end());
      lli cont=0;
      for(lli i=0; i<s.size(); ++i){
        if(s[i]=='0') continue;
        if(s2[i]=='1'){
          if(cont==1){
            s2[i]='0';
            cont++;
          }
        }
        else{
          s2[i]='1';
          cont++;
        }
      }
      if(cont==0) return -1;
      lli val=0;
        lli pow2=1;
        for(lli i=s2.size()-1; i>=0; --i){
          if(s2[i]=='1') val+=pow2;
          pow2*=2;
        }
        return val;

      
    }
    void solve(){
      lli n;
      cin>>n;
      s="";
      lli aux=n;
      while(aux>0){
        if(aux%2) s+="1";
        else s+="0";
        aux/=2;
      }
      reverse(s.begin(), s.end());
   //   deb(s);
      lli act=next(-1);
      vector<lli> ans;
      ans.pb(act);
      while(true){
        act=next(act);
        if(act==-1) break;
        ans.pb(act);
      }
      cout<<ans.size()<<endl;
      for(lli i=0; i<ans.size(); ++i){
        cout<<ans[i]<<" ";
      }
      cout<<endl;

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