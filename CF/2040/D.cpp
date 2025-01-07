    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    vector<bool> primo;

    void criba(){
        primo.resize(4e5+5, true);
        primo[1]=false;
        for(lli i=2; i<primo.size(); ++i){
            if(!primo[i]) continue;
            for(lli j=i*i; j<primo.size(); j+=i){
                primo[j]=false;
            }
        }
    }
    vector<lli> values;
    lli act;
    void dfs(lli x, lli p, vector<vector<lli>> &ady){
        if(x==0){
            values[x]=act;
            act++;
            for(lli y: ady[x]){
                dfs(y, 0, ady);
            }
        }
        else{
            while(primo[act-values[p]]) act++;
            values[x]=act;
            act++;
            for(lli y: ady[x]){
                if(y==p) continue;
                dfs(y, x, ady);
            }
        }
    }
    void solve(){
        lli n;
        cin>>n;
        vector<vector<lli>> ady(n);
        act=1;
        values.clear();
        values.resize(n);
        for(lli i=0; i<n-1; ++i){
            lli u,v;
            cin>>u>>v;
            u--;
            v--;
            ady[u].pb(v);
            ady[v].pb(u);
        }
        values[0]=1;
        dfs(0, -1, ady);
        for(lli i=0; i<n; ++i){
            cout<<values[i]<<" ";
        }
        cout<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
        cin>>t;
        criba();
        while(t--){
            solve();
        }
    }