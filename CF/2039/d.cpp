    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    vector<lli> primes;
    void Criba(){
        vector<bool> vis (1e3+5, false);
        for(lli i=2; i<=1e3; ++i){
            if(vis[i]) continue;
            primes.pb(i);
            for(lli j=i*i; j<=1e3; j+=i){
                vis[j]=true;
            }
        }
    }

    void solve(){
        lli n,m;
        cin>>n>>m;
        vector<lli> ans (n+1);
        vector<lli> v (m);
        for(lli i=0; i<m; ++i){
            cin>>v[m-1-i];
        }

        for(lli i=1; i<=n; ++i){
            lli aux=i;
            lli sum=0;
            for(lli primo: primes){
                if(aux==1) break;
                while(aux%primo==0){
                    sum++;
                    aux/=primo;
                }
            }
            if(aux!=1){
                sum+=1;
            }
            if(sum>=m){
                cout<<-1<<endl;
                return;
            }
            ans[i]=v[sum];
        }
        for(lli i=1; i<=n; ++i){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
        Criba();
        cin>>t;
        while(t--){
            solve();
        }
    }