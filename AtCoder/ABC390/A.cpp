    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    bool check (vector<lli> &v){
        for(lli i=0; i<5; ++i){
            if(v[i]!=i+1) return false;
        }
        return true;
    }
    void solve(){
        vector<lli> v (5);
        for(lli i=0; i<5; ++i){
            cin>>v[i];
        }
        for(lli i=0; i<4; ++i){
            swap(v[i], v[i+1]);
            if(check(v)){
                cout<<"Yes"<<endl;
                return;
            }
            swap(v[i], v[i+1]);
        }
        cout<<"No"<<endl;

    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
  //      cin>>t;
        while(t--){
            solve();
        }
    }