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
            cin>>v[i];
        }
        priority_queue<lli, vector<lli>, greater<lli>> pq;
        vector<lli> ans(n);
        for(lli i=0; i<n; ++i){
            while(!pq.empty() && pq.top()<i){
                pq.pop();
            }
            v[i]+=pq.size();

            pq.push(i+v[i]);
            ans[i]=max(0ll, v[i]-n+i+1);
        }
        for(lli i=0; i<n; ++i){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
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