    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    void agregar(lli a, lli c, vector<lli> &v ){
        for(lli i=v.size(); i>=0; --i){
            if(i+c<v.size()){
                v[i+c]=max(v[i+c], v[i]+a);
            }
        }
    }

    void solve(){
        lli n,x;
        cin>>n>>x;
        vector<lli> v1 (5005,0);
        vector<lli> v2 (5005, 0);
        vector<lli> v3 (5005, 0);
        for(lli i=0; i<n; ++i){
            lli v,a,c;
            cin>>v>>a>>c;
            if(v==1){
                agregar(a,c,v1);
            }
            if(v==2){
                agregar(a,c,v2);
            }
            if(v==3){
                agregar(a,c,v3);
            }
        }
        for(lli i=1; i<5005; ++i){
            v1[i]=max(v1[i], v1[i-1]);
            v2[i]=max(v2[i], v2[i-1]);
            v3[i]=max(v3[i], v3[i-1]);
        }
        lli ans=0;
        for(lli i=0; i<=x; ++i){
            for(lli j=0; j<=x-i; ++j){
              
                ans=max(ans, min(v1[i], min(v2[j], v3[x-i-j])));
            }
        }
        cout<<ans<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
  //      cin>>t;
        while(t--){
            solve();
        }
    }