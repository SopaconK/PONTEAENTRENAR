    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    

    void calc(lli x, lli k, map<lli,lli> & inc, map<lli,lli> & num, map<lli,bool> &vis){
        if(vis[x]) return;
        vis[x]=true;
        if(x<k){
            inc[x]=0;
            num[x]=0;
            return;
        }
        calc(x/2, k, inc, num, vis);
        if(x%2==1){
            num[x]=2*num[x/2]+1;
            inc[x]=2*inc[x/2]+(x/2+1)*(num[x/2]+1);
        }
        else{
            num[x]=2*num[x/2];
            inc[x]=2*inc[x/2]+(x/2)*num[x/2];
        }
   //     deb(x);
    //    deb(num[x]);
      //  deb(inc[x]);
    }

    void solve(){
        lli n,k;
        cin>>n>>k;
        map<lli,lli> inc;
        map<lli,lli> num;
        map<lli,bool> vis;
        calc(n,k,inc, num, vis);
        cout<<inc[n]<<endl;
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