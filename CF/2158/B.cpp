    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        n*=2;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i) cin>>v[i];
        vector<lli> val (n+1);
        for(lli i=0; i<n; ++i){
            val[v[i]]++;
        }

        lli a=0;
        lli b=0;
        for(lli i=0; i<=n; ++i){
            if(val[i]>0){
                if(val[i]%2){
                    a++;
                }
                else b++;
            }
        }
        lli k=n/2;
        k-=b;
        lli x=k;
        lli y=k;
    //    deb(k);
      //  deb(a);
        //deb(b);

       lli ans=2*b;
       while(a>0){
        if(x>0){
            if(y>0){
                if(x%2) x--;
                else y--;
            }
            else{
                x--;
            }
        }
        else y--;
        a--;
        ans++;
       }
       if(x%2 || y%2) ans-=2;
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