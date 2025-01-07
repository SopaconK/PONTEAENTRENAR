    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m;
        cin>>n>>m;
        vector<lli> a(n);
        vector<lli> b(m);
        for(lli i=0; i<n; ++i) cin>>a[i];
        for(lli i=0; i<m; ++i) cin>>b[i];
        vector<lli> aux (2e5+5, -1);
        for(lli i=0; i<n; ++i){
            if(aux[a[i]]==-1) aux[a[i]]=i+1;
        }
        lli act=-1;
        for(lli i=0; i<aux.size(); ++i){
            if(aux[i]==-1){
                aux[i]=act;
            }
            else{
                if(act==-1){
                    act=aux[i];
                }
                else{
                    act=min(act, aux[i]);
                    aux[i]=act;
                }
            }
        }
        vector<lli> ans (m);
        for(lli i=0; i<m; ++i){
            ans[i]=aux[b[i]];
        }
        for(lli i=0; i<m; ++i){
            cout<<ans[i]<<endl;
        }

    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
     //   cin>>t;
        while(t--){
            solve();
        }
    }