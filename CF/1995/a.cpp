    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
  //  #define endl '\n'


    void solve(){
        lli n,k;
        cin>>n>>k;
        priority_queue<lli> pq;
        for(lli i=1; i<n; ++i){
            pq.push(i);
            pq.push(i);
        }
        pq.push(n);
        lli ans=0;
        while(k>0){
      //      deb(k);
            ans++;
            k-=pq.top();
            pq.pop();
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