    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<vector<lli>> v (n, vector<lli> (n));
        for(lli i=0; i<n; ++i){
            for(lli j=0; j<n; ++j){
                cin>>v[i][j];
            }
        }
        vector<lli> unos (n+5,0);
        for(lli i=0; i<n; ++i){
            lli ans=0;
            for(lli j=n-1; j>=0; --j){
                if(v[i][j]==1){
                    ans++;
                }
                else{
                    break;
                }
            }
            unos[ans]++;
        }
        
        lli ans;
        lli sum=n;
        lli pend=0;
        for(lli i=0; i<n+5; ++i){
            if(unos[i]>0){
                sum-=unos[i];
                while(unos[i]>1 && pend>0){
                    unos[i]--;
                    pend--;
                }
            }
            else{
                pend++;
            }
            
            if(sum<pend){
                ans=i;
                break;
            }
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