    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m,k;
        cin>>n>>m>>k;
        lli a=k-1;
        lli b=n-k;
        if(a<b) swap(a,b);
    
        lli ans=0;
        for(lli i=0; i<=b; ++i){
            // m>=2x-1+y =>  (m-y+1)/2 >=x
            lli x=(m-i+1)/2;
            if(m+1<i) continue;
            x=min(x, a);
            if(x<i) continue;
          //  deb(i+x+1);
         
            ans=max(ans, i+x+1);


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