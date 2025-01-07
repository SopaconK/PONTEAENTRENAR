    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli l,r;
        cin>>l>>r;
        vector<lli> v1 (20,0);
        vector<lli> v2 (20,0);
        lli ind=0;
        while(ind<20){
            v1[ind]=r%10;
            v2[ind]=l%10;
            l/=10;
            r/=10;
            ind++;
        }
        ind=19;
        while(v1[ind]==0) ind--;
        lli ans=0;
    //    deb(ind);
         for(lli i=v2[ind]+1; i<v1[ind]; ++i){
                ans+=pow(i, ind);
            }
        lli x=v1[ind];
        lli y=v2[ind];
        ind--;
        bool a=true;
        bool b=true;
    //    deb(ans);
 //   deb(x);
   // deb(y);
        if(x!=y){
        while(ind>=0){
            if(a){
            if(v1[ind]<x){
           for(lli i=0; i<v1[ind]; ++i){
            ans+=pow(x, ind);
           }
            }
            else{
                for(lli i=0; i<x; ++i){
            ans+=pow(x, ind);
           }
           a=false;
            }
            }
           // deb(ans);
            if(b){
                if(y==0){
                    y=v2[ind];
                }
                else{
   //                 deb(y);
     //               deb(v2[ind]);
                    if(v2[ind]>=y){
                        b=false;
                    }
                    else{
                        for(lli i=v2[ind]+1; i<y; ++i){
                            ans+=pow(y, ind);
                        }
                    }
                }
            }
         //   deb(ans);
            ind--;
        }
        if(a) ans++;
        if(b) ans++;
        }
        else{
            while(v1[ind]==v2[ind]){
                if(v1[ind]>=x) break;
                ind--;
            }

     //       deb(ans);
             for(lli i=v2[ind]+1; i<v1[ind] && i<x; ++i){
                ans+=pow(i, ind);
            }
            ind--;
     //       deb(ans);
            while(ind>=0){
            if(a){
            if(v1[ind]<x){
           for(lli i=0; i<v1[ind]; ++i){
            ans+=pow(x, ind);
           }
            }
            else{
                for(lli i=0; i<x; ++i){
            ans+=pow(x, ind);
           }
           a=false;
            }
            }
       //     deb(ans);
            if(b){
                if(y==0){
                    y=v2[ind];
                }
                else{
   //                 deb(y);
     //               deb(v2[ind]);
                    if(v2[ind]>=y){
                        b=false;
                    }
                    else{
                        for(lli i=v2[ind]+1; i<y; ++i){
                            ans+=pow(y, ind);
                        }
                    }
                }
            }
         //   deb(ans);
            ind--;
        }
        if(a) ans++;
        if(b) ans++;
        }
        cout<<ans<<endl;
        
    }





    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
      //  cin>>t;
        while(t--){
            solve();
        }
    }