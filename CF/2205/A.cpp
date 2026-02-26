    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        lli indaux=-1;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
            if(v[i]==n) indaux=i;
        }
        swap(v[0], v[indaux]);
        for(lli i=0; i<n; ++i) cout<<v[i]<<" ";
        cout<<endl;
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