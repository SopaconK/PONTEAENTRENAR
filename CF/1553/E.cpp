    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    lli find (lli a, vector<lli> &v){
        if(v[a]==a) return a;
        return v[a]=find(v[a],v);
    }
    void unir(lli a, lli b, vector<lli> &v){
        a=find(a,v);
        b=find(b,v);
        v[a]=b;
    }
    void solve(){
        lli n,m;
        cin>>n>>m;
        vector<lli> v (n);
        vector<lli> cant (n,0);
        lli inv=0;
        for(lli i=0; i<n; ++i){
            cin>>v[i];
            v[i]--;
            lli xd=n+i-v[i];
            xd%=n;
            cant[xd]++;
        }
        vector<lli> ans;
        for(lli i=0; i<n; ++i){
            if(cant[i]>=n-2*m){
                vector<lli> aux (n);
                for(lli j=i; j<n; ++j){
                    aux[j-i]=v[j];
                }
                for(lli j=0; j<i; ++j){
                    aux[n+j-i]=v[j];
                }
                vector<lli> par (n);
                for(lli j=0; j<n; ++j){
                    par[j]=j;
                }
                for(lli j=0; j<n; ++j){
                    unir(j, aux[j], par);
                }
                lli cant=0;
                for(lli j=0; j<n; ++j){
                    if(find(j, par)==j) cant++;
                }
                cant=n-cant;
                if(cant<=m) ans.pb(i);
            }
        }
        cout<<ans.size()<<" ";
        for(lli x: ans) cout<<x<<" ";
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