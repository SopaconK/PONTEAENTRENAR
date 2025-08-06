    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    lli gcd(lli a,lli b){
        return __gcd(a,b);
    }

    lli lcm(lli a, lli b){
        return (a*b)/gcd(a,b);
    }

    void solve(){
        lli n;
        cin>>n;
        vector<lli> ab (n);
        vector<lli> b (n);
        for(lli i=0; i<n; ++i){
            cin>>ab[i]>>b[i];
            ab[i]*=b[i];
        }

        lli ans=1;
        lli g=ab[0];
        lli l=b[0];
        for(lli i=1; i<n; ++i){
            g=gcd(g, ab[i]);
            l=lcm(l, b[i]);
            if(g%l!=0){
                ans++;
                g=ab[i];
                l=b[i];
            }
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