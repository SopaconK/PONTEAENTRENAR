    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,s1,s2;
        cin>>n>>s1>>s2;
        vector<vector<lli>> a (n+1);
        vector<vector<bool>> adya (n+1, vector<bool> (n+1,0));
        lli m;
        cin>>m;
        for(lli i=0; i<m; ++i){
            lli x,y;
            cin>>x>>y;
            adya[x][y]=1;
            adya[y][x]=1;
            a[x].pb(y);
            a[y].pb(x);
        }
        vector<vector<lli>> b (n+1);
        lli m2;
        cin>>m2;
        vector<vector<bool>> adyb (n+1, vector<bool> (n+1,0));
        for(lli i=0; i<m2; ++i){
            lli x,y;

            cin>>x>>y;
            adyb[x][y]=1;
            adyb[y][x]=1;
            b[x].pb(y);
            b[y].pb(x);
        }

        vector<bool> pos (n+1,0);
        for(lli i=1; i<=n; ++i){
            for(lli j=1; j<=n; ++j){
                if(adya[i][j] && adyb[i][j]){
                    pos[i]=1;
                    pos[j]=1;
                }
            }
        }

        vector<vector<lli>> est (n+1, vector<lli> (n+1,1e18));
        
        priority_queue<pair<lli,pair<lli,lli>>, vector<pair<lli,pair<lli,lli>>>, greater<pair<lli,pair<lli,lli>>>>pq;
        pq.push({0,{s1,s2}});

        lli ans=1e18;
        while(!pq.empty()){
            lli p=pq.top().first;
            lli x=pq.top().second.first;
            lli y=pq.top().second.second;
            pq.pop();
       //     deb(x);
         //   deb(y);
           // deb(p);
            //deb(est[x][y]);
            if(est[x][y]<p) continue;
            if(x==y){
                if(pos[x]){
                    ans=min(ans, p);
                }
            }
            for(lli u: a[x]){
       //         deb(u);
                for(lli v: b[y]){
         //           deb(u);
           //         deb(v);
                    lli val=p+abs(u-v);
    //                deb(val);
                    if(est[u][v]>val){
                        est[u][v]=val;
                        pq.push({val,{u,v}});
                    }
                }
            }
        }
        if(ans==1e18) ans=-1;
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