    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,k;
        cin>>n>>k;
        vector<lli> a (n);
        vector<lli> b (n);
        for(lli i=0; i<n; ++i){
            cin>>a[i];
        }
        for(lli i=0; i<n; ++i){
            cin>>b[i];
        }

        if(k%2==0){
            vector<lli> sum (n);
            sum[0]=a[0];
           
            for(lli i=1; i<n; ++i){
                sum[i]=sum[i-1]+a[i];
            }
            
            vector<lli> mini(n,0);
            for(lli i=1; i<n; ++i){
                mini[i]=min(mini[i-1], sum[i-1]);
            }
            vector<lli> maxi(n,-1e15);
            maxi[n-1]=max(maxi[n-1], sum[n-1]);
            
            for(lli i=n-2; i>=0; --i){
                maxi[i]=max(maxi[i+1], sum[i]);
            }
            
            lli ans=a[0];
            for(lli i=0; i<n; ++i){
                ans=max(ans, maxi[i]-mini[i]);
            }
            cout<<ans<<endl;
            return;
        }
        else{
             vector<lli> sum (n);
            sum[0]=a[0];
           
            for(lli i=1; i<n; ++i){
                sum[i]=sum[i-1]+a[i];
            }
            
            vector<lli> mini(n,0);
            for(lli i=1; i<n; ++i){
                mini[i]=min(mini[i-1], sum[i-1]);
            }
            vector<lli> maxi(n,-1e15);
            maxi[n-1]=max(maxi[n-1], sum[n-1]);
            
            for(lli i=n-2; i>=0; --i){
                maxi[i]=max(maxi[i+1], sum[i]);
            }

          lli ans=a[0];
            for(lli i=0; i<n; ++i){
                ans=max(ans, maxi[i]+b[i]-mini[i]);
            }
            cout<<ans<<endl;
            return;


        }
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