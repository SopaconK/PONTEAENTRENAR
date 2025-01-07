    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'



    void solve(){
        lli n,m;
        cin>>n>>m;
        lli powtwo=1;
        while(powtwo<=n){
            powtwo*=2;
        }
        lli ans=0;
        if(m<powtwo){
             for(lli y=1; y<=m; ++y){
            lli xd=n^y;
           
            if(xd%n==0 ||xd%y==0){
                ans++;
            }
           
        }
         cout<<ans<<endl;
            return;
        }
        for(lli y=1; y<powtwo; ++y){
            lli xd=n^y;
            if(xd%n==0) continue;
            if(xd%y==0){
                ans++;
    //            deb(y);
            }
        }
    
      lli auxi=m/powtwo;
      auxi*=powtwo;
   //   deb(auxi);
      ans+=(auxi-1)/n;
      for(lli y=auxi; y<=m; ++y){
          lli xd=n^y;
           
            if(xd%n==0){
                ans++;
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