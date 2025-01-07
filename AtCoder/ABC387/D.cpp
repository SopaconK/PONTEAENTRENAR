    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
 //   #define endl '\n'


    void solve(){
        lli h,w;
        cin>>h>>w;
        vector<string> v (h);
        for(lli i=0; i<h; ++i){
            cin>>v[i];
        }
        vector<vector<lli>> ady (2*h*w);
        lli goal;
        queue<pair<lli,lli>> q;
        for(lli i=0; i<h; ++i){
            for(lli j=0; j<w; ++j){
                lli a=i*w+j;
                lli b=a+h*w;
                if(v[i][j]!='#'){
                    if(j!=0){
                        if(v[i][j-1]!='#'){
                        ady[b].pb(a-1);
                       // ady[a-1].pb(b);
                        }
                    }
                    if(i!=0){
                        if(v[i-1][j]!='#'){
                        ady[a].pb(b-w);
                      //  ady[b-w].pb(a);
                        }
                    }
                    if(j!=w-1){
                        if(v[i][j+1]!='#'){
                      //  ady[a+1].pb(b);
                        ady[b].pb(a+1);}
                    }
                    if(i!=h-1){
                        if(v[i+1][j]!='#'){
                        ady[a].pb(b+w);
                       // ady[b+w].pb(a);
                        }
                    }
                }
                if(v[i][j]=='S'){
                    q.push({a,0});
                    q.push({b,0});
                }
                if(v[i][j]=='G'){
                    goal=a;
                }
        //        deb(i);
          //      deb(j);
            }
        }
        vector<lli> vis ( 2*h*w, -1);
    
        while(!q.empty()){
            lli x=q.front().first;
            lli y=q.front().second;
            q.pop();



            for(lli z: ady[x]){
                if(vis[z]==-1){
  //                  deb(x);
    //                deb(z);
                    vis[z]=y+1;
                    q.push({z,y+1});
                }
            }
        }
        lli ans=-1;
        if(vis[goal]!=-1){
            ans=vis[goal];
        }
        if(vis[goal+h*w]!=-1){
            if(ans==-1) ans=vis[goal+h*w];
            else{
                ans=min(ans, vis[goal+h*w]);
            }
        }
        cout<<ans<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
      //  cin>>t;
        while(t--){
            solve();
        }
    }