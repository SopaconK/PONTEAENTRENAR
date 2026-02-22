    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> red (n);
        vector<lli> blue (n);
        for(lli i=0; i<n; ++i){
            cin>>red[i];
        }
        for(lli i=0; i<n; ++i){
            cin>>blue[i];
        }

        lli maxi=0;
        lli mini=0;
        for(lli i=0; i<n; ++i){
            lli a=maxi;
            lli b=mini;
            lli c,d;
            lli s=a-red[i];
            c=s;
            d=s;
            s=b-red[i];
            c=max(c, s);
            d=min(d, s);
            s=blue[i]-a;
            c=max(c, s);
            d=min(d, s);
            s=blue[i]-b;
            c=max(c, s);
            d=min(d, s);
            maxi=c;
            mini=d;
           
        }
        cout<<maxi<<endl;
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