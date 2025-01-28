    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

        void dfs(lli x, lli p,lli h, vector<vector<lli>> &ady, vector<lli> &euler, vector<pair<lli,lli>> &pos, vector<vector<lli>> &altura, vector<lli> &alt, vector<bool> &vis, vector<lli> &org){
        pos[x].first=euler.size();
        vis[x]=true;
        euler.pb(0);
        org[pos[x].first]=x;
        alt[x]=h;
        altura[h].pb(pos[x].first);
        for(lli y: ady[x]){
            if(y==p) continue;
            dfs(y,x,h+1,ady,euler,pos,altura, alt,vis,org);
        }
        pos[x].second=euler.size();
        euler.pb(0);
    }

    lli binaria1(vector<lli> &v, lli x){ //ultimo < a x
        if(v.size()==0) return -1;
        if(v[0]>=x) return -1;
        lli l=0;
        lli r=v.size()-1;
        while(l<r-1){

            lli m=(l+r)/2;
            if(v[m]<x){
                l=m;
            }
            else{
                r=m-1;
            }
        }
        if(v[r]<x) l=r;
        return l;
    }

    lli binaria2(vector<lli> &v, lli a, lli b){ //cuantos entre [a,b]
        lli c=binaria1(v, a);
        lli d=binaria1(v,b);
  //      for(lli i:v){
    //        deb(i);
      //  }
        //deb(c);
        //deb(d);
        return d-c;
    }

    void solve(){
        lli n;
        cin>>n;


            vector<vector<lli>> sons(n);
        for(lli i=0; i<n; ++i){
            lli p;
            cin>>p;
            if(p!=0){
                p--;
                sons[p].pb(i);
            }
        }
        vector<lli> euler;
        vector<pair<lli,lli>> pos(n, {0,0});
        vector<lli> org (2*n);
        vector<vector<lli>> altura (n);
        vector<lli> alt(n);
        vector<bool> vis (n,0);
        for(lli i=0; i<n; ++i){
        if(vis[i]) continue;
        dfs(i,-1,0,sons,euler,pos,altura,alt, vis,org);
        }
        lli q;
        cin>>q;
        while(q--){
            lli v,p;
            cin>>v>>p;
            v--;
            lli xd=alt[v]-p;
 //           deb(xd);
            if(xd<0){
                cout<<0<<" ";
                continue;
            }
   //         deb(altura[xd][binaria1(altura[xd], pos[v].first)]);
            lli a=org[altura[xd][binaria1(altura[xd], pos[v].first)]];
     //       deb(a);
       //     deb(pos[a].first);
         //   deb(pos[a].second);
            lli ans=binaria2(altura[alt[v]],pos[a].first, pos[a].second);
           // deb(ans);
            cout<<ans-1<<" ";
        }
        cout<<endl;
        
    }  




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
   //     cin>>t;
        while(t--){
            solve();
        }
    }