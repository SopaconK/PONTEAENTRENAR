    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> v (n+1,0);
        for(lli i=0; i<n; ++i){
            lli x;
            cin>>x;
            if(x<=n){
                v[x]++;
            }
        }
        vector<lli> ans (n+1,0);
        for(lli i=1; i<=n; ++i){
            if(v[i]>0){
                for(lli j=i; j<=n; j+=i){
                    ans[j]+=v[i];
                }
            }
        }
        lli maxi=0;
        for(lli i=0; i<=n; ++i){
            maxi=max(maxi, ans[i]);
        }
        cout<<maxi<<endl;
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