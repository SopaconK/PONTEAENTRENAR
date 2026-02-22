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
        vector<lli> v2(n);
        for(lli i=0; i<n; ++i) cin>>v[i];
        for(lli i=0; i<n; ++i) cin>>v2[i];

        vector<lli> maxi1 (n);
        vector<lli> maxi2 (n);
        vector<lli> mini1(n);
        vector<lli> mini2(n);
        maxi1[0]=v[0];
        maxi2[n-1]=v2[n-1];
        mini1[0]=v[0];
        mini2[n-1]=v2[n-1];
        for(lli i=1; i<n; ++i){
            maxi1[i]=max(maxi1[i-1], v[i]);
            mini1[i]=min(mini1[i-1], v[i]);
        }

        for(lli i=n-2; i>=0; --i){
            maxi2[i]=max(maxi2[i+1], v2[i]);
            mini2[i]=min(mini2[i+1], v2[i]);
        }

        // for(lli i=0; i<n; ++i){
        //     cout<<maxi1[i]<<" ";
        // }
        // cout<<endl;
        // for(lli i=0; i<n; ++i){
        //     cout<<maxi2[i]<<" ";
        // }
        // cout<<endl;
        // for(lli i=0; i<n; ++i){
        //     cout<<mini1[i]<<" ";
        // }
        // cout<<endl;
        // for(lli i=0; i<n; ++i){
        //     cout<<mini2[i]<<" ";
        // }
        // cout<<endl;

        vector<lli> ans (2*n+1,1e10);
        for(lli i=0; i<n; ++i){
            lli ind=min(mini1[i], mini2[i]);
            ans[ind]=min(ans[ind], max(maxi1[i], maxi2[i]));
        }
        for(lli i=2*n-1; i>=1; --i){
            ans[i]=min(ans[i], ans[i+1]);
        }

        lli an=0;
        for(lli i=1; i<=2*n; ++i){
            if(ans[i]<=2*n){
                an+=(2*n+1-ans[i]);
            }
        }
        cout<<an<<endl;
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