    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m;
        cin>>n>>m;
        vector<vector<lli>> v (m+1, vector<lli> (m+1));
        vector<lli> a (m+1,0);
        vector<lli> b (m+1,0);
        lli cant=0;
        for(lli i=0; i<n; ++i){
            lli x;
            cin>>x;
            if(x==0){
                for(lli i=1; i<=m; ++i){
                    a[i]+=a[i-1];
                    b[i]+=b[i-1];
                    
                }
                for(lli i=0; i<=m; ++i){
                    v[cant][i]+=a[i];
                }
                for(lli i=0; i<=cant; ++i){
                    v[cant][i]+=b[cant-i];
                }

                cant++;

                for(lli i=0; i<=m; ++i){
                    a[i]=0;
                    b[i]=0;
                }
            }
            else{
                if(x<0){
                    b[-x]++;
                }
                else a[x]++;
            }
        }
        for(lli i=1; i<=m; ++i){
                    a[i]+=a[i-1];
                    b[i]+=b[i-1];
                    
                }
                for(lli i=0; i<=m; ++i){
                    v[cant][i]+=a[i];
                }
                for(lli i=0; i<=cant; ++i){
                    v[cant][i]+=b[cant-i];
                }
        for(lli i=m-1; i>=0; --i){
            
            for(lli j=0; j<=i; ++j){
             //   deb(i);
               // deb(j);
             //   deb(v[i][j]);
                v[i][j]+=max(v[i+1][j], v[i+1][j+1]);
               // deb(v[i][j]);
            }
              
        }
        cout<<v[0][0]<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
    //    cin>>t;
        while(t--){
            solve();
        }
    }