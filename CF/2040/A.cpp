    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,k;
        cin>>n>>k;
        vector<lli> cant (k, 0);
        vector<lli> ex (k, -1);
        for(lli i=0; i<n; ++i){
            lli x;
            cin>>x;
            cant[x%k]++;
            ex[x%k]=i+1;
        }
        for(lli i=0; i<k; ++i){
            if(cant[i]==1){
                cout<<"YES"<<endl<<ex[i]<<endl;
                return;
            }
        }
        cout<<"NO"<<endl;
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