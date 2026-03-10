    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
  //  #define endl '\n'

    string s;
    lli ans=0;

    void dfs(vector<vector<bool>> & st, lli x, lli y, lli m){
        // deb(x);
        // deb(y);
        // deb(m);
        // deb(s[m]);
        // deb("-----");
        if(x==0 && y==6){
            if(m!=48) return;
            ans++;
            return;
        }
        if(m==48){
            return;
        }
        if((s[m]=='?' || s[m]=='D') && y<6){
            if(!st[x][y+1]){
                st[x][y+1]=1;
                bool hacer=1;
                if(y+1==6 || st[x][y+2]){
                    lli cant=0;
                    if(x>0){
                        if(!st[x-1][y+1]) cant++;
                    }
                    if(x<6){
                        if(!st[x+1][y+1]) cant++;
                    }
                    if(cant>=2) hacer=0;
                }

                if(hacer) dfs(st, x, y+1, m+1);
                st[x][y+1]=0;
            }
        }
        if((s[m]=='?' || s[m]=='R') && x<6){
        
            if(!st[x+1][y]){
                st[x+1][y]=1;
                bool hacer=1;
                if(x+1==6 || st[x+2][y]){
                    lli cant=0;
                    if(y>0){
                        if(!st[x+1][y-1]) cant++;
                    }
                    if(y<6){
                        if(!st[x+1][y+1]) cant++;
                    }
                    if(cant>=2) hacer=0;
                }

                if(hacer) dfs(st, x+1, y, m+1);
                st[x+1][y]=0;
            }
        }
        if((s[m]=='?' || s[m]=='U') && y>0){
            if(!st[x][y-1]){
                st[x][y-1]=1;
                bool hacer=1;
                if(y-1==0 || st[x][y-2]){
                    lli cant=0;
                    if(x>0){
                        if(!st[x-1][y-1]) cant++;
                    }
                    if(x<6){
                        if(!st[x+1][y-1]) cant++;
                    }
                    if(cant>=2) hacer=0;
                }

                if(hacer) dfs(st, x, y-1, m+1);
                st[x][y-1]=0;
            }
        }
        if((s[m]=='?' || s[m]=='L') && x>0){
            if(!st[x-1][y]){
                st[x-1][y]=1;
                  bool hacer=1;
                if(x-1==0 || st[x-2][y]){
                    lli cant=0;
                    if(y>0){
                        if(!st[x-1][y-1]) cant++;
                    }
                    if(y<6){
                        if(!st[x-1][y+1]) cant++;
                    }
                    if(cant>=2) hacer=0;
                }

                if(hacer) dfs(st, x-1, y, m+1);
                st[x-1][y]=0;
            }
        }
        
    }

    void solve(){
        cin>>s;
        vector<vector<bool>> st(7, vector<bool> (7,0));
        st[0][0]=1;
        dfs(st, 0, 0, 0);
        cout<<ans<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
       // cin>>t;
        while(t--){
            solve();
        }
    }