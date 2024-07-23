    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m;
        cin>>n>>m;
        vector<lli> a (n);
        vector<lli> v (n);
        map<lli,lli> mp;
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }
        for(lli i=0; i<n; ++i){
            cin>>a[i];
            mp[v[i]]=a[i];
        }
        lli ans=0;
        map<lli,bool> visi;
        for(lli x: v){
            if(visi[x]) continue;
            visi[x]=true;
            lli a=mp[x];
            lli b=mp[x+1];
            lli c=m/x;
            c=min(c,a+b);
            lli l=max(0ll, c-a);
            lli r=min(c, b);
            if(c*x+r>=m && c*x+l<=m){
                cout<<m<<endl;
                return;
            }
            while(c*x+l>m){
                lli d=(c*x+l-m);
                d=(d-1)/(x+1);
                d++;

                c-=(d);
                l=max(0ll, c-a);
                r=min(c, b);
                 if(c*x+r>=m && c*x+l<=m){
                cout<<m<<endl;
                return;
               }
            }
            ans=max(ans, c*x+r);
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