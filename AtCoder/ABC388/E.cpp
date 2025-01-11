    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }
        lli ans1=0;
        vector<bool> vis (n,0);
        lli p=0;
        for(lli i=0; i<n; ++i){
            if(vis[i]) continue;
            while(p<n && v[p]<2*v[i]){
                p++;
            }
            if(p<n){
                ans1++;
                vis[p]=true;
                p++;
            }

        }
         lli ans2=0;
        vector<bool> vis2 (n,0);
        p=n-1;
        for(lli i=n-1; i>=0; --i){
            if(vis2[i]) continue;
            while(p>=0 && 2*v[p]>v[i]){
                p--;
            }
            if(p>=0){
                ans2++;
                vis2[p]=true;
                p--;
            }

        }
        lli ans=max(ans1,ans2);

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