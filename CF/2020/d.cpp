    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    vector<lli> f;

    int find(lli x){
        if(f[x]==x) return x;
        return f[x]=find(f[x]);
    }



    void merge (lli a, lli b){
        int fa=find(a );
        int fb=find(b);
        f[fa]=fb;
    }

    void solve(){
        lli n,m;
        cin>>n>>m;
        map<pair<lli,lli>, vector<pair<lli,lli>>> mp;
        for(lli i=0; i<m; ++i){
            lli a,d,k;
            cin>>a>>d>>k;
            mp[{d, a%d}].pb({a, a+d*k});
        }
        vector<lli> ans (n+1);
        f.clear();
        f.resize(n+1);
        for(lli i=1; i<=n; ++i){
            ans[i]=i;
            f[i]=i;
        }
        
        for(lli i=1; i<=10; ++i){
            for(lli j=0; j<i; ++j){
                lli p1=0;
                if(mp[{i,j}].size()==0) continue;
                vector<lli> aux (n+1);
                for(lli ayuda=1; ayuda<=n; ++ayuda){
                    aux[ayuda]=ayuda;
                }
                
                sort(mp[{i,j}].begin(), mp[{i,j}].end());
                for(lli p2=j; p2<=n; p2+=i){
                    if(p1<mp[{i,j}].size()){
                        if(p2>mp[{i,j}][p1].second){
                            p1++;
                            p2-=i;
                        }
                        else{
                            if(p2>mp[{i,j}][p1].first){
                                aux[p2]=aux[mp[{i,j}][p1].first];
                            }
                        }
                    }
                    else break;
                }
                
                for(lli p2=j; p2<=n; p2+=i){
                    merge(ans[aux[p2]], ans[p2]);
                    ans[p2]=ans[aux[p2]];   
                }

            }
        }
        lli slv=0;
        for(lli i=1; i<=n; ++i){
            if(find(i)==i) slv++;
        }
        cout<<slv<<endl;
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