    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m;
        cin>>n>>m;
        vector<vector<bool>> v (n, vector<bool> (n,0));
        while(m--){
            char c;
            cin>>c;
            lli a,b;
            cin>>a>>b;
            a--;
            b--;
            v[a][b]=1;
            if(c=='N'){
                if(a-2>=0){
                    if(b-1>=0){
                        v[a-2][b-1]=1;
                    }
                    if(b+1<n){
                        v[a-2][b+1]=1;
                    }
                }
                if(a-1>=0){
                    if(b-2>=0){
                        v[a-1][b-2]=1;
                    }
                    if(b+2<n){
                        v[a-1][b+2]=1;
                    }
                }
                if(a+1<n){
                    if(b-2>=0){
                        v[a+1][b-2]=1;
                    }
                    if(b+2<n){
                        v[a+1][b+2]=1;
                    }
                }
                if(a+2<n){
                    if(b-1>=0){
                        v[a+2][b-1]=1;
                    }
                    if(b+1<n){
                        v[a+2][b+1]=1;
                    }
                }
            }
            if(c=='R'){
                for(lli i=0; i<n; ++i){
                    v[i][b]=1;
                    v[a][i]=1;
                }
            }
            if(c=='Q'){
                for(lli i=0; i<n; ++i){
                    v[i][b]=1;
                    v[a][i]=1;
                }
                lli x=a;
                lli y=b;
                while(x>=0 && y>=0 && x<n && y<n){
                    v[x][y]=1;
                    x--;
                    y--;
                }
                x=a;
                y=b;
                while(x>=0 && y>=0 && x<n && y<n){
                    v[x][y]=1;
                    x--;
                    y++;
                }
                x=a;
                y=b;
                while(x>=0 && y>=0 && x<n && y<n){
                    v[x][y]=1;
                    x++;
                    y--;
                }
                x=a;
                y=b;
                while(x>=0 && y>=0 && x<n && y<n){
                    v[x][y]=1;
                    x++;
                    y++;
                }
            }
        }
        lli ans=0;
        for(lli i=0; i<n; ++i){
            for(lli j=0; j<n; ++j){
                if(v[i][j]) ans++;
            //    cout<<v[i][j]<<" ";
            }
           // cout<<endl;
         
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