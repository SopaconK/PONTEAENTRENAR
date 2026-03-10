    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
//    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> cub;
        cub.pb(0);
        while(cub[cub.size()-1]<=n){
            cub.pb((cub.size())*(cub.size())*(cub.size()));
        }
        cub.pb((cub.size())*(cub.size())*(cub.size()));
        cub.pb((cub.size())*(cub.size())*(cub.size()));
         cub.pb((cub.size())*(cub.size())*(cub.size()));
        vector<lli> v;
        v.pb(0);
       lli valmin=1;
        while(valmin<cub.size() && v[v.size()-1]<=n){    
         //   deb(valmin);
            while(true){
                if(valmin >=cub.size()) break;
                if(v[v.size()-1]+cub[valmin]<cub[valmin+1]){
                    break;
                }
                valmin++;
            }
            if(valmin>=cub.size()) v.pb(-1);
            else v.pb(v[v.size()-1]+cub[valmin]);
           // deb(v[v.size()-1]);
          
        }
        cout<<v.size()-2<<" ";
        lli ans=0;
        lli indc=cub.size()-1;
        lli ind=v.size()-2;
        while(ind>0){
       //     deb(n);
         //   deb(ind);
            if(v[ind]==n){
                ans+=n;
                break;
            }
            while(cub[indc]>n) indc--;
            lli d=n-cub[indc];
            lli s=cub[indc];
            while(d<v[ind-1]){
                indc--;
                d=cub[indc+1]-1-cub[indc];
                s=cub[indc];
            }
            n=d;
            ans+=s;
            ind--;
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