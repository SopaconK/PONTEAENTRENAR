    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,w,h;
        cin>>n>>w>>h;
        vector<lli> a(n);
        vector<lli> b (n);
        vector<lli> c (n);
        vector<lli> d (n);
        for(lli i=0; i<n; ++i){
            lli x;
            cin>>x;
            a[i]=x-w;
            b[i]=x+w;
        }
        for(lli i=0; i<n; ++i){
            lli x;
            cin>>x;
            c[i]=x-h;
            d[i]=x+h;
        }

        lli minim=-1e18;
        lli maxim=1e18;
        for(lli i=0; i<n; ++i){
            minim=max(minim, a[i]-c[i]);
            maxim=min(maxim, b[i]-d[i]);
        }
        if(minim>maxim){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;

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