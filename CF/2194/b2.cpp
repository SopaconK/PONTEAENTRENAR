    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,x,y;
        cin>>n>>x>>y;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }

        if(x==y){
            lli s=0;
            lli s2=0;
            lli maxi=0;
            for(lli i=0; i<n; ++i){
                s2+=v[i];
                v[i]%=x;
                s+=v[i];
                maxi=max(maxi, v[i]);
            }
            s-=maxi;
            lli ans=s2-s;
            cout<<ans<<endl;
            return;
        }
        lli ans=0;
        for(lli i=0; i<n; ++i ){
            ans+=v[i];
        }
     //   deb(ans);
        lli d=__gcd(x,y);
        vector<lli> t (x);
        for(lli i=0; i<(x/d); ++i){
            for(lli j=0; j<d; ++j){
            t[(i*y+j)%x]=(x/d)-i;
      //      deb((i*y+j)%x);
        //    deb((x/d)-i);
            
            }
        }
        t[0]=0;
        vector<lli> cost (n,0);
        for(lli i=0; i<n; ++i){
     //       deb(t[v[i]%x]);
            cost[i]=min((v[i]/x)*(x-y)+v[i]%x, (v[i]/x)*(x-y)+v[i]%d+t[v[i]%x]*(x-y));
            deb(cost[i]);
        }
        sort(cost.rbegin(), cost.rend());
        lli s=0;
        for(lli i=1; i<n; ++i){
            s+=cost[i];
        }
    //   deb(s);
        ans-=s;
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