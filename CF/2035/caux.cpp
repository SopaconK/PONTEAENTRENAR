    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> v(n);
        for(lli i=0; i<n; ++i){
            v[i]=i+1;
        }
        lli maxi=0;
        do{
            lli k=0;
            for(lli i=1; i<=n; ++i){
                if(i%2==0){
                    k|=v[i-1];
                }
                else{
                    k&=v[i-1];
                }
            }
            if(k>=maxi){
                cout<<k<<endl;
                for(lli i=0; i<n; ++i){
                    cout<<v[i]<<" ";
                }
                cout<<endl;
                maxi=k;
            }
        }while(next_permutation(v.begin(), v.end()));
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