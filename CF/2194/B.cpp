    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

lli gcdExtended(lli a, lli b, lli* x, lli* y)
{
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    lli x1, y1;
    lli gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
lli modInverse(lli A, lli M)
{
    lli x, y;
    lli g = gcdExtended(A, M, &x, &y);
    
        lli res = (x % M + M) % M;
        return res;
}


    void solve(){
        lli n,x,y;
        cin>>n>>x>>y;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }

        if(x==y){
            lli s=0;
            lli s2=0;
            lli maxi=0;
            for(lli i=0; i<n; ++i){
                s2+=v[i];
                v[i]%=x;
                s+=v[i];
                maxi=max(maxi, v[i]);
            }
            s-=maxi;
            lli ans=s2-s;
            cout<<ans<<endl;
            return;
        }
        lli ans=0;
        for(lli i=0; i<n; ++i ){
            ans+=v[i];
        }
     //   deb(ans);
        lli d=__gcd(x,y);
        lli y2=y/d;
        lli inv=modInverse(y2, (x/d));
        vector<lli> t (n);
        for(lli i=0; i<n; ++i){
           lli aux=v[i]/d;
            t[i]=-aux*inv;
            t[i]%=(x/d);
            t[i]+=(x/d);
            t[i]%=(x/d);
       //     deb(t[i]);
        }
        
        vector<lli> cost (n,0);
        for(lli i=0; i<n; ++i){
            cost[i]=min((v[i]/x)*(x-y)+v[i]%x, (v[i]/x)*(x-y)+v[i]%d+t[i]*(x-y));
     //       deb(cost[i]);
        }
        sort(cost.rbegin(), cost.rend());
        lli s=0;
        for(lli i=1; i<n; ++i){
            s+=cost[i];
        }
    //   deb(s);
        ans-=s;
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