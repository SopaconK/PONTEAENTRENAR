#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
//#define endl '\n'
#define deb(x) cout<<#x<<": "<<x<<endl;
vector<vector<pair<lli,lli>>> ady;
vector<vector<lli>> sons;
vector<lli> v1;
vector<lli> v2;
vector<lli> v3;
vector<lli> sum;
const lli MOD=1e9+7;

lli c=0;
lli ans=0;
void dfs(lli x, lli p,lli h){
    v1[x]=c;
    v3[c]=x;
    c++;
   // sum[x]=s;
    ans+=((h)/2);
    for(pair<lli,lli> i: ady[x]){
        if(i.first==p) continue;
        dfs(i.first, x, h+1);
        sons[x].pb(i.first);
    }
    v2[x]=c;
    v3[c]=x;
    c++;
}

vector<pair<lli,lli>> cosos;

lli cant (lli s, lli a, lli b){
 //   deb(s);
 //   deb(a);
  //  deb(b);
    lli ind1;
    if(cosos[0].first>s) return 0;
    if(cosos[cosos.size()-1].first<s) return 0;
    if(cosos[cosos.size()-1].first==s && cosos[cosos.size()-1].second <a) return 0;
    if(cosos[0].first==s && cosos[0].second>b) return 0;
    if(cosos[0].first==s && cosos[0].second>=a) ind1=0;
    else{
  //      deb("xd?");
        lli l=0; //Primero que no es
        lli r=cosos.size()-1; //Primero que puede ser
        while(r-l>1){
            lli m=(l+r)/2;
            if(cosos[m].first<s) l=m; //no puede ser
            else if(cosos[m].first>s) r=m;
            else{
                if(cosos[m].second<a){
                    l=m;
                }
                else{
                    r=m;
                }

            }
        }
        
        if(cosos[r].first==s) ind1=r;
        else return 0;
 //       deb(ind1);
    }

    lli ind2;

    if(cosos[0].first==s && cosos[0].second >b) return 0;
    if(cosos[cosos.size()-1].first==s && cosos[cosos.size()-1].second<a) return 0;
    if(cosos[cosos.size()-1].first==s && cosos[cosos.size()-1].second<=b) ind2=cosos.size();
    else{
        lli l=0; //Primero que puede ser
        lli r=cosos.size(); //Primero que no es
        while(r-l>1){
            lli m=(l+r)/2;
            if(cosos[m].first<s) l=m; //no puede ser
            else if(cosos[m].first>s) r=m;
            else{
                if(cosos[m].second>b){
                    r=m;
                }
                else{
                    l=m;
                }

            }
        }
        if(cosos[l].first==s) ind2=r;
        else return 0;
//        deb(ind2);
    }
    return ind2-ind1;

}

void dfs2(lli x, lli y){
    
    if(x==y){
        for(lli s: sons[y]){
            dfs2(s, y);
        }
        return;
    }
 //   deb(x);
   // deb(y);
   // deb(ans);
    ans+=cant(sum[y]+2*(sum[x]-sum[y]), v1[x]+1, v2[x]);
   // deb(ans);
    for(lli s: sons[x]){
            dfs2(s, y);
    }
}

void dfs3(lli x){
  //  deb(x);
    dfs2(x,x);
    for(lli s: sons[x]){
        dfs3(s);
    }
}

void solve(){
    lli n;
    cin>>n;
    ady.resize(n);
    v1.resize(n);
    v2.resize(n);
    v3.resize(2*n);
    sum.resize(n);
    sons.resize(n);
    //cosos.resize(n);
    for(lli i=0; i<n-1; ++i){
        lli u,v,c;
        cin>>u>>v>>c;
        u--;
        v--;
        ady[u].pb({v,c});
        ady[v].pb({u,c});
    }
    dfs(0,-1, 0);
  //  deb("dfs");
//    for(lli i=0; i<n; ++i){
  //      cosos.pb({sum[i], v1[i]});
  //  }
 //   sort(cosos.begin(), cosos.end());

 //   for(lli i=0; i<n; ++i){
   //     cout<<cosos[i].first<<" "<<cosos[i].second<<endl;
    //}
   // deb("sor");
 //   dfs3(0);
    cout<<ans<<endl;


    

    
    

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}