    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
   // #define endl '\n'


   lli query (lli x, lli y){
    x++; 
    y++;
    cout<<"? "<<x<<" "<<y<<endl;
    lli ans;
    cin>>ans;
    return ans;
   }

    void solve(){
        lli n,q;
        cin>>n>>q;
        vector<lli> v (n,-1);
        for(lli i=0; i<q; ++i){
            lli l,r;
            cin>>l>>r;
            l--;
            r--;
            v[l]=max(v[l],r);
        }
        vector<pair<lli,lli>> rg;
        lli lim=-1;
        for(lli i=0; i<n; ++i){
            if(v[i]!=-1){
                if(lim<v[i]){
                    rg.pb({i,v[i]});
                    lim=v[i];
                }
            }
        }
        lli l=0;
        lli r=rg.size()-1;
        lli ans=0;
        while(l<=r){
             lli m=(l+r)/2;
             lli a=query(0, rg[m].second);
             lli b=query(rg[m].first, n-1);
             ans=max(ans, min(a,b));
             if(a>b){
                r=m-1;
             }
             else{
                l=m+1;
             }
        }
        

        cout<<"! "<<ans<<endl;

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