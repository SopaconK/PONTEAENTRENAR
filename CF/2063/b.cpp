    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        lli a,b;
        cin>>a>>b;
        a--;
        b--;
        vector<lli> v(n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
          
        }
        lli ans=1e10;
        lli sum=0;
        for(lli i=a; i<=b; ++i){
            sum+=v[i];
        }
        ans=sum;
        //caso 1
        priority_queue<lli, vector<lli>, greater<lli>> pq;
        priority_queue<lli> pq2;
        for(lli i=0; i<a; ++i){
            pq.push(v[i]);
        }
        for(lli i=a; i<=b; ++i){
            pq2.push(v[i]);
        }
        lli aux=sum;
        while(!pq.empty() && !pq2.empty()){
            if(pq.top()>=pq2.top()) break;
            aux+=pq.top()-pq2.top();
            pq.pop();
            pq2.pop();
        }
        ans=min(ans, aux);

       while(!pq.empty()) pq.pop();
       while(!pq2.empty()) pq2.pop();

       for(lli i=b+1; i<n; ++i){
        pq.push(v[i]);
       }
       for(lli i=a; i<=b; ++i){
            pq2.push(v[i]);
        }
        aux=sum;
        while(!pq.empty() && !pq2.empty()){
            if(pq.top()>=pq2.top()) break;
            aux+=pq.top()-pq2.top();
            pq.pop();
            pq2.pop();
        }
        ans=min(ans, aux);
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