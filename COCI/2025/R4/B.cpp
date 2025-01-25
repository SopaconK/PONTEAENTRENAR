    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,d,x;
        cin>>n>>d>>x;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }
        vector<pair<lli,lli>> r (n);
        for(lli i=0; i<n; ++i){
            lli a;
            cin>>a;
            r[i]={v[i], a};
        }
        sort(r.begin(), r.end());
        priority_queue<lli> pq;
        lli ans=0;
        lli p=0;
        while(d<x){
        while(p<n && r[p].first<=d){
            pq.push(r[p].second);
            p++;
        }
        if(pq.empty()){
            cout<<-1<<endl;
            return;
        }
        ans++;
        d+=pq.top();
        pq.pop();
        }
        cout<<ans<<endl;
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