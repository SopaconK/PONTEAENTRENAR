    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<vector<lli>> v (n);
        for(lli i=0; i<n; ++i){
            lli s;
            cin>>s;
            map<lli, bool> us;
            vector<lli> ax (s);
            for(lli j=0; j<s; ++j) cin>>ax[j];

            for(lli j=s-1; j>=0; --j){
                lli x=ax[j];
                if(us[x]!=1){
                    v[i].pb(x);
                    us[x]=1;
                }
            }
        }
        vector<lli> ans;

        vector<bool> used (n,0);
        map<lli,bool> mp;
        lli cantused=0;
        vector<lli> v2;
        while(cantused<n){
           // deb(cantused);
            vector<lli> aux;
            lli indi=-1;
            for(lli i=0; i<n; ++i){
                
                if(used[i]) continue;
                v2.clear();
                for(lli j=0; j<v[i].size(); ++j){
                    if(mp[v[i][j]]!=1) v2.pb(v[i][j]);
                }
                swap(v[i], v2);

     //           deb("...");
       //         deb(i);
         //       for(lli x: v[i]) cout<<x<<" ";
           //     cout<<endl;

                if(v[i].size()==0){
                    used[i]=1;
                    cantused++;
                    continue;
                }

                lli ind=0;
                if(aux.size()==0){
                    aux=v[i];
                    indi=i;
                }
                while(true){
                    
                    if(aux.size()<=ind){
                        break;
                    }
                    if(v[i].size()<=ind){
                        aux=v[i];
                        indi=i;
                        break;
                    }
                    if(v[i][ind]<aux[ind]){
                        aux=v[i];
                        indi=i;
                        break;
                    }
                    if(v[i][ind]>aux[ind]){
                        break;
                    }
                    ind++;
                }
            }
     //       deb(indi);
            for(lli i=0; i<aux.size(); ++i){
                if(mp[aux[i]]!=1){
                    ans.pb(aux[i]);
                    mp[aux[i]]=1;
                }
            }
            if(indi!=-1){
                used[indi]=1;
                cantused++;
            }
        }
        for(lli x: ans){
            cout<<x<<" ";  
        }
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