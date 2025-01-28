    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
   // #define endl '\n'
  

    void dfs(lli x, lli d, vector<vector<pair<lli,lli>>> &sons, priority_queue<lli> &pq){
       // deb(x);
        for(auto y: sons[x]){
      //      deb(y.first);
            priority_queue<lli> aux;
            dfs(y.first,y.second,sons, aux);
            if(aux.size() >pq.size()){
                swap(aux, pq);
            }
            
            while(!aux.empty()){
                pq.push(aux.top());
                aux.pop();
            }
          
        }
        if(pq.empty()){
            pq.push(0);
            pq.push(0);
//            deb(pq.size());
        }
    
            for(lli i=0; i<((lli) sons[x].size())-1; ++i){
            //    deb(i);
                pq.pop();
            }
            lli a=pq.top();
            pq.pop();
            lli b=pq.top();
            pq.pop();
  //          deb(a);
    //        deb(b);
            a+=d;
            b+=d;
            pq.push(a);
            pq.push(b);

        
    }
    void solve(){
       lli n,m;
       cin>>n>>m;
       vector<vector<pair<lli,lli>>> sons (n+m+1);
       lli sum=0;
       for(lli i=2; i<=n+m; ++i){
        lli p, c;
        cin>>p>>c;
        sum+=c;
        sons[p].pb({i,c});
       }
       priority_queue<lli> ans;
       dfs(1,0,sons,ans);
       lli val=sum;
        lli pend=1-ans.size();
        lli ant=0;
        stack<lli> v;
        while(!ans.empty()){
            v.push(ans.top());
            ans.pop();
        }
        while(!v.empty()){
            sum+=pend*(v.top()-ant);
            val=min(val, sum);
            pend++;
            ant=v.top();
            v.pop();
        }
        cout<<val<<endl;


    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        lli t=1;
     //   cin>>t;
        while(t--){
            solve();
        }
    }