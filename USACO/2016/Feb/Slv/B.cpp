    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    using ld=long double;

    void solve(){
        lli n;
        cin>>n;
        map<lli, vector<lli>> mpx;
        map<lli, vector<lli>> mpy;
        for(lli i=0; i<n; ++i){
            lli x,y;
            cin>>x>>y;
            mpx[x].pb(i);
            mpy[y].pb(i);
        }
        lli ans=n;
        lli a=0, b=0, c=0, d=n;
        vector<lli> ye (n, 1);
        for(auto rec: mpy){
            b+=a;
            a=0;
            d+=c;
            c=0;
            for(lli y: rec.second){
                b++;
                d--;
                ye[y]=0;
            }
            ans=min(ans, max(a, max(b,max(c,d))));
            for(auto coso: mpx){
                for(lli x: coso.second){
                    if(ye[x]){
                        d--;
                        c++;
                    }
                    else{
                        b--;
                        a++;
                    }
                }
                 ans=min(ans, max(a, max(b,max(c,d))));
            }
        }
        cout<<ans<<endl;
    }




    int main(){
        freopen("balancing.in", "r", stdin);
        freopen("balancing.out", "w", stdout);
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
       // cin>>t;
        while(t--){
            solve();
        }
    }