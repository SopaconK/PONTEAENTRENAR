    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    
    void dfs(lli x, vector<vector<lli>> &sons, vector<lli> &depth){
        if(sons[x].size()==0){
            depth[x]=0;
            return;
        }
        vector<lli> sn;
        for(lli y: sons[x]){
            dfs(y, sons, depth);
            sn.pb(depth[y]);
        }
        sort(sn.rbegin(),sn.rend());
        queue<int> q;
        while(sn.size()+q.size()>2){
            if(!q.empty()){
                if(!sn.empty()){
                if(q.front()<=sn[sn.size()-1]){
                    q.pop();
                }
                else{
                    sn.pop_back();
                }
                }
                else{
                    q.pop();
                }
            }
            else{
                sn.pop_back();
            }
            lli a;
            if(!q.empty()){
                if(!sn.empty()){
                if(q.front()<=sn[sn.size()-1]){
                    a=q.front();
                    q.pop();
                }
                else{
                    a=sn[sn.size()-1];
                    sn.pop_back();
                }
                }
                else{
                    a=q.front();
                    q.pop();
                }
            }
            else{
                a=sn[sn.size()-1];
                sn.pop_back();
            }
            a++;
            q.push(a);
        }
        while(!q.empty()){
            sn.push_back(q.front());
            q.pop();
        }
        lli a=0;
        for(lli si:sn){
            a=max(a,si);
        }
        depth[x]=a+1;
    }

    void solve(){
        lli n;
        cin>>n;
        vector<vector<lli>> sons (n+1);
        vector<lli> par (n+1);
        vector<lli> depth (n+1);
        par[1]=0;
        for(lli i=2; i<=n; ++i){
            cin>>par[i];
            sons[par[i]].pb(i);
        }
        dfs(1, sons, depth);
        cout<<depth[1]<<endl;

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