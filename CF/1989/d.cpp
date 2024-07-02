    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'



    void solve(){
        int n,m;
        cin >>n>>m;
        vector<int> a (n);
        vector<int> b(n);
        vector<pair<int,int>> v;
        for(int i=0; i<n; ++i){
            cin>>a[i];
        }
        for(int i=0; i<n; ++i){
            cin>>b[i];
            v.pb({a[i],a[i]-b[i]});
        }
        sort(v.begin(), v.end());
        vector<int> values(m);
        int maxi=0;
        for(int i=0; i<m; ++i){
            cin>>values[i];
        }
        int x=0;
        int ind=0;
        vector<lli> dp (1000001,0);
        for(lli i=1; i<dp.size(); ++i){
            while(ind<v.size() && v[ind].first<=i){
                if(x==0){
                    x=v[ind].second;
                }
                else{
                    x=min(x, v[ind].second);
                }
                ind++;
            }
            dp[i]=dp[i-x]+1;
            if(x==0) dp[i]=0;
            
        }
        lli ans=0;
        for(lli si: values){
            if(si>1000000){
                lli dif=si-1000000;
                dif/=x;
                si-=dif*x;
                ans+=dif;
                if(si>1000000){
                    ans++;
                    si-=x;
                }
            }
            ans+=dp[si];
        }
        ans*=2;
        cout<<ans<<endl;
        

    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
        //cin>>t;
        while(t--){
            solve();
        }
    }