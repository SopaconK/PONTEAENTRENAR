    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    lli n,m;
    void dfs(lli x, lli y, vector<string> &grid, lli &sz, lli &minr, lli &maxr, lli &minc, lli &maxc){
        sz++;
        minr=min(minr,x);
        maxr=max(maxr,x);
        minc=min(minc,y);
        maxc=max(maxc,y);
        grid[x][y]='1';
        if(x-1>=0){
            if(grid[x-1][y]=='#') dfs(x-1,y,grid,sz,minr,maxr,minc,maxc);
        }
        if(y-1>=0){
            if(grid[x][y-1]=='#') dfs(x,y-1,grid,sz,minr,maxr,minc,maxc);
        }
        if(x+1<n){
            if(grid[x+1][y]=='#') dfs(x+1,y,grid,sz,minr,maxr,minc,maxc);
        }
        if(y+1<m){
            if(grid[x][y+1]=='#') dfs(x, y+1, grid, sz,minr,maxr,minc,maxc);
        }
    }

    void solve(){
        cin>>n>>m;
        vector<string> grid (n );
        for(lli i=0; i<n; ++i){
            cin>>grid[i];
        }
        vector<pair<lli,lli>> column;
        vector<pair<lli,lli>> row;

        for(lli i=0; i<n; ++i){
            for(lli j=0; j<m; ++j){
                if(grid[i][j]=='#'){
                    lli minr=n+1;
                    lli maxr=-1;
                    lli minc=m+1;
                    lli maxc=-1;
                    lli sz=0;
                    dfs(i,j,grid,sz,minr,maxr,minc,maxc);
                    column.pb({minc-1, sz});
                    column.pb({maxc+2, -sz});
                    row.pb({minr-1, sz});
                    row.pb({maxr+2,-sz});
 //                   deb(i);
   //                 deb(j);
     //               deb(sz);
       //             deb(minr);
         //           deb(maxr);
                }
            }
        }

        sort(column.begin(), column.end());
        sort(row.begin(), row.end());

        lli ans=0;

        lli sum=0;
        lli ind=0;
        for(lli i=0; i<n; ++i){
            while(ind<row.size() && row[ind].first<=i){
                sum+=row[ind].second; 
                ind++;
            }
            lli act=sum;
            for(lli j=0; j<m; ++j){
                if(grid[i][j]=='.') act++;
            }
  //          deb(i);
    //        deb(sum);
      //      deb(act);
            ans=max(ans, act);
        }

        sum=0;
        ind=0;
        for(lli i=0; i<m; ++i){
            while(ind<column.size() && column[ind].first<=i){
                sum+=column[ind].second; 
                ind++;
            }
            lli act=sum;
            for(lli j=0; j<n; ++j){
                if(grid[j][i]=='.') act++;
            }
            ans=max(ans, act);
  //           deb(i);
    //        deb(sum);
      //      deb(act);
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