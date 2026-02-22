    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,k;
        cin>>n>>k;
        vector<lli> dp1 (32,0); // sin carry 
        vector<lli> dp2 (32,-1e10); // deja carry 
        for(lli cnt=0; cnt<32; ++cnt){
            vector<lli> dp1a (32,0);
            vector<lli> dp2a (32,-1e10);
            if(n%2){
                for(lli i=0; i<32; ++i){
                    dp1a[i]=dp1[i];
                    dp2a[i]=dp2[i]+1;
                    if(i>0){
                        dp2a[i]=max(dp2a[i], dp2[i-1]+1);
                        dp2a[i]=max(dp2a[i], dp1[i-1]+1);    
                    }
                }
            }
            else{
                for(lli i=0; i<32; ++i){
                    dp1a[i]=max(dp1[i], dp2[i]);
                    if(i>0){
                        dp2a[i]=dp2[i-1]+1;
                    }
                }
            }
            n/=2;
            dp1=dp1a;
            dp2=dp2a;
          
        }
        lli ans=0;
        for(lli i=0; i<=min(31ll, k); ++i){
           
            ans=max(ans, max(dp1[i]+(k-i), dp2[i]+k-i));
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