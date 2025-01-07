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
            v[i]=i+1;
        }
        do{
            lli sum=0;
            for(lli i=0; i<n; ++i){
                lli mini=v[i];
                for(lli j=i; j<n; ++j){
                    mini=min(mini, v[j]);
                    sum+=mini;
                }
            }
            for(lli i=0; i<n; ++i){
                cout<<v[i]<<" ";
            }
            cout<<endl;
            deb(sum);
        }while(next_permutation(v.begin(), v.end()));
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
      //  cin>>t;
        while(t--){
            solve();
        }
    }