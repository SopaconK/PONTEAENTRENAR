    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        map<lli, lli> mpx;
        map<lli,lli> mpy;
        map<lli,lli> mps;
        map<lli,lli> mpd;
        for(lli i=0; i<n; ++i){
            lli x,y;
            cin>>x>>y;
            mpx[x]++;
            mpy[y]++;
            mpd[x-y]++;
            mps[x+y]++;
        }
        lli ans=0;
        for(auto a: mpx){
            ans+=(a.second)*(a.second-1);
        }
         for(auto a: mpy){
            ans+=(a.second)*(a.second-1);
        }
         for(auto a: mpd){
            ans+=(a.second)*(a.second-1);
        }
         for(auto a: mps){
            ans+=(a.second)*(a.second-1);
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