    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m;
        cin>>n>>m;
  
        vector<pair<lli,lli>> v;
        map<lli,lli> can;
        for(lli i=0; i<n; ++i){
            lli l;
            cin>>l;
            map<lli,lli> mp;
            for(lli j=0; j<l; ++j){
                lli a;
                cin>>a;
                mp[a]=1;
            }
            lli cnt=0;
            lli ind=0;
            lli x,y;
            while(cnt<2){
                if(mp[ind]==0){
                    cnt++;
                   if(cnt==1) x=ind;
                   else y=ind;
                }
                ind++;
            }
            v.pb({x,y});
        }
        sort(v.begin(), v.end());
        map<lli,lli> dp;
        lli def=v[v.size()-1].first;
        for(lli i=v.size()-1; i>=0; --i){
            dp[v[i].first]=max(dp[v[i].first], v[i].second);
            dp[v[i].first]=max(dp[v[i].first], dp[v[i].second]);
            can[v[i].first]++;
        }
        for(lli i=0; i<v.size(); ++i){
            if(can[v[i].first]>1){
                def=max(def, dp[v[i].first]);
            }
        }
        lli sum=0;
        map<lli,bool> vis;
        lli num=0;
        for(lli i=0; i<v.size(); ++i){
           if(vis[v[i].first]) continue;
            if(m<v[i].first) continue;
            sum+=max(def, dp[v[i].first]);
            num++;
            vis[v[i].first]=true;
        }
    
        if(m<=def){
            lli ans=def*(m+1-num);
            ans+=sum;
            cout<<ans<<endl;
        }
        else{
             lli ans=def*(def+1-num);
            ans+=sum;
            lli aux=(m*(m+1))/2;
            lli aux2=(def*(def+1))/2;
            ans+=aux-aux2;
            cout<<ans<<endl;
        }
        
   
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