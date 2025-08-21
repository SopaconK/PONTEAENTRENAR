    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<pair<lli,lli>> v;
        lli sum=0;
        v.pb({0,0});
        for(lli i=1; i<=n; ++i){
            lli x;
            cin>>x;
            sum+=x;
            v.pb({sum, i});
        }
        sort(v.begin(), v.end());
        vector<pair<lli,lli>> rangos;
        for(lli i=1; i<v.size(); ++i){
            if(v[i-1].first==v[i].first){
                rangos.pb({v[i].second, v[i-1].second+1});
            }
        }
        sort(rangos.begin(), rangos.end());
        lli ans=0;
        lli aux=0;
        for(auto a: rangos){
            if(a.second>aux){
                ans++;
                aux=a.first;
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