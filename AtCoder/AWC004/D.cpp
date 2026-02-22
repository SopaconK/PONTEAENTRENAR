    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m;
        cin>>n>>m;
        vector<pair<lli,lli>> v (m);
        for(lli i=0; i<m; ++i){
            lli l,r;
            cin>>l>>r;
            l--;
            r--;
            v[i]={l,r};
        }
        sort(v.begin(), v.end());
       priority_queue<lli, vector<lli>, greater<lli>> q;
       lli ind=0;
       for(lli i=0; i<n; ++i){
        
        while(ind <m && v[ind].first==i){
            q.push(v[ind].second);
            ind++;
        }

        if(!q.empty()){
            if(q.top()>=i){
                q.pop();
            }
            else{
                cout<<"No"<<endl;
                return;
            }
        }

       }
       if(q.empty()){
        cout<<"Yes"<<endl;
       }
       else{
        cout<<"No"<<endl;
       }
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