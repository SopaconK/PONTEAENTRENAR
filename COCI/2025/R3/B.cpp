    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m,x,y;
        cin>>n>>m>>x>>y;
        vector<vector<bool>> v (n, vector<bool> (m));
        vector<lli> cant (n,0);
        vector<lli> cant2(m,0);
        for(lli i=0; i<n; ++i){
            string s;
            cin>>s;
            for(lli j=0; j<m; ++j){
                if(s[j]=='0') v[i][j]=0;
                else{
                    v[i][j]=true;
                    cant[i]++;
                    cant2[j]++;
                } 
            }
        }
        vector<bool> take (n,true);
        vector<bool> take2 (m, true);
        bool chn1=false;
         bool chn2=false;
        for(lli i=0; i<n; ++i){
            
            if(cant[i]<=x) {
          //      deb(i);
                take[i]=false;
                chn1=true;
            }
        }
        for(lli i=0; i<m; ++i){
            if(cant2[i]<=y){
                
         //       deb("y");
           //     deb(i);
            
                take2[i]=false;
                chn2=true;
            }
        }

        for(lli i=0; i<n; ++i){
            cant[i]=0;
        }
        for(lli i=0; i<m; ++i){
            cant2[i]=0;
        }

        for(lli i=0; i<n; ++i){
            if(!take[i]) continue;
            for(lli j=0; j<m; ++j){
                if(!take2[j]) continue;
                if(v[i][j]){
                    cant[i]++;
                    cant2[j]++;
                }
            }
        }
        while(chn1!=false || chn2!=false){
             chn1=false;
          chn2=false;
        for(lli i=0; i<n; ++i){
            if(!take[i]) continue;
            if(cant[i]<=x) {
                take[i]=false;
                chn1=true;
            }
        }
        for(lli i=0; i<m; ++i){
            if(!take2[i]) continue;
            if(cant2[i]<=y){
                take2[i]=false;
                chn2=true;
            }
        }

        for(lli i=0; i<n; ++i){
            cant[i]=0;
        }
        for(lli i=0; i<m; ++i){
            cant2[i]=0;
        }

        for(lli i=0; i<n; ++i){
            if(!take[i]) continue;
            for(lli j=0; j<m; ++j){
                if(!take2[j]) continue;
                if(v[i][j]){
                    cant[i]++;
                    cant2[j]++;
                }
            }
        }   
        }
       
        lli ans=0;
        for(lli i=0; i<n; ++i){
            if(take[i]){
                ans+=cant[i];
                ans-=x;
            }
        }
        for(lli i=0; i<m; ++i){
            if(take2[i]){
                ans-=y;
            }
        }
        ans=max(0ll, ans);
        cout<<ans<<endl;




        

    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        solve();
        
    }