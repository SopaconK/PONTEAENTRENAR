    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,k;
        cin>>n>>k;
        vector<vector<lli>> v (n, vector<lli> (n,0));
        for(lli i=0; i<n; ++i){
            for(lli j=i; j<n; ++j){
                cin>>v[i][j];
            }
        }
        vector<vector<lli>> dp (n,vector<lli> (k,-1e15)); // si la ultima esta vacia
        vector<lli> aux={0, v[0][0]};
        sort(aux.rbegin(), aux.rend());
        dp[0][0]=aux[0];
        if(k>1) dp[0][1]=aux[1];
        for(lli i=1; i<n; ++i){
          

            vector<lli> ind (i,0);
           priority_queue<pair<lli,lli>> pq;
           for(lli j=0; j<i-1; ++j){
            pq.push({dp[j][0]+v[j+2][i], j});
           }
           pq.push({dp[i-1][0], i-1});
           pq.push({v[1][i], i});
           pq.push({v[0][i], i});
           for(lli x=0; x<k; ++x){
                dp[i][x]=pq.top().first;
                lli y=pq.top().second;
                pq.pop();
                if(y<i-1){
                    ind[y]++;
                    if(ind[y]<k){
                        pq.push({dp[y][ind[y]]+v[y+2][i], y});
                    }
                }
                else if(y==i-1){
                    ind[y]++;
                    pq.push({dp[y][ind[y]], i-1});
                }
           }

    
           
        }
        for(lli i=0; i<k; ++i){
            cout<<dp[n-1][i]<<" ";
        }
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