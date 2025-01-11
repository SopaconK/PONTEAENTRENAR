    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    lli dfs(lli x,vector<lli> &v, vector<vector<lli>> & sons, vector<lli> &l , vector<lli> & r){
        lli ans=0;
        lli sum=0;
        for(lli y: sons[x]){
            ans+=dfs(y, v, sons, l, r);
            sum+=v[y];
        }
        if(sum<l[x]){
            ans++;
            v[x]=r[x];
            return ans;
        }
        sum=min(sum, r[x]);
        v[x]=sum;
        return ans;
    }

    void solve(){
        lli n;
        cin>>n;
        vector<vector<lli>> sons (n);
        vector<lli> l (n);
        vector<lli> r (n);
        for(lli i=1; i<n; ++i){
            lli p;
            cin>>p;
            p--;
            sons[p].pb(i);
        }
        for(lli i=0; i<n; ++i){
            cin>>l[i]>>r[i];
        }
        vector<lli> v (n,0);
        cout<<dfs(0, v, sons,l,r)<<endl;
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