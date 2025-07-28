    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    using ld=long double;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
lli area(vector<pair<lli,lli>> v){
        if(v.size()<=2) return 0;
        lli val=0;
        lli n=v.size();
        for(lli i=0; i<n-1; ++i){
            val+=v[i].first*v[i+1].second-v[i+1].first*v[i].second;
        }
        val+=v[n-1].first*v[0].second;
        val-=v[0].first*v[n-1].second;

        return abs(val);
    }
   
    vector<pair<lli,lli>> points;
lli n;


    void solve(){
        lli k;
        cin>>n>>k;
        points.resize(n, {0,0});
        for(lli i=0; i<n; ++i){
            cin>>points[i].first>>points[i].second;
        }
    
        

     
        
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
    //    cin>>t;
        while(t--){
            solve();
        }
    }