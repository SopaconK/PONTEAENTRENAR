    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    using ld=long double;

    void solve(){
        lli n,m,d,s;
        cin>>n>>m>>d>>s;
        vector<vector<lli>> sk (n, vector<lli> (m, 1e9));
        vector<lli> sik (n, -1);
        while(d--){
            lli p,m,t;
            cin>>p>>m>>t;
            sk[p-1][m-1]=min(sk[p-1][m-1],t);
        }
        while(s--){
            lli p,t;
            cin>>p>>t;
            sik[p-1]=t;
        }
        lli ans=0;
        for(lli i=0; i<m; ++i){
            bool pos=true;
            for(lli j=0; j<n; ++j){
                if(sik[j]!=-1){
                    if(sk[j][i]>= sik[j]){
                        pos=false;
                    }
                }
            }
            if(pos){
                lli aux=0;
                for(lli j=0; j<n; ++j){
                    if(sk[j][i]<1e9) aux++;
                }
                ans=max(ans, aux);
            }
        }
        cout<<ans<<endl;

    }




    int main(){
        freopen("badmilk.in", "r", stdin);
        freopen("badmilk.out", "w", stdout);
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
     //   cin>>t;
        while(t--){
            solve();
        }
    }