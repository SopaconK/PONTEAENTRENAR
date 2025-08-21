    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }
        lli ans=0;
        for(lli i=0; i<n; ++i){
            if(v[i]!=2) continue;
            ans++;
            lli aux=i;
            while(aux>=0){
                if(v[aux]>0){
                    v[aux]=-1;
                    aux--;
                }
                else{
                    v[aux]=-1;
                    break;
                }
            }
            aux=i+1;
            while(aux<n){
                 if(v[aux]>0){
                    v[aux]=-1;
                    aux++;
                }
                else{
                    v[aux]=-1;
                    break;
                }
            }
        }
        vector<lli> a;
        a.pb(v[0]);
        for(lli i=1; i<n; ++i){
            if(v[i]==0) a.pb(0);
            else{
                if(v[i]==v[i-1]) continue;
                a.pb(v[i]);
            }
        }
        lli ceros=0;
        lli unos=0;
        for(lli i=0; i<a.size(); ++i){
            if(a[i]==-1){
                ans+=unos;
                ceros-=unos;
                if(ceros>0) ans+=ceros;
                ceros=0;
                unos=0;
            }
            else{
                if(a[i]==0) ceros++;
                else unos++;
            }
        }
        ans+=unos;
                ceros-=unos;
                if(ceros>0) ans+=ceros;
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