    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m;
        cin>>n>>m;
        lli val=0;
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
            while(cnt<2){
                if(mp[ind]==0){
                    cnt++;
                    val=max(val, ind);
                }
                ind++;
            }
        }
       
        lli ans;
        if(m>val){
            ans=val*(val+1);
            lli aux=(m*(m+1))/2;
            lli aux2=(val*(val+1))/2;
            
            ans+=aux;
            ans-=aux2;
        }
        else{
            ans=val*(m+1);
        }
        cout<<ans<<endl;
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