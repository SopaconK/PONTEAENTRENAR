    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
     lli n,h,k;
     cin>>n>>h>>k;
     vector<lli> v (n);
     lli s=0;
     for(lli i=0; i<n; ++i){
        cin>>v[i];
        s+=v[i];
     }
     lli ans=0;
     ans=h/s;
     ans*=(n+k);
     if(h%s==0){
        ans-=k;
        cout<<ans<<endl;
        return;
     }
     vector<lli> mini (n);
     vector<lli> maxi(n);
     mini[0]=v[0];
     for(lli i=1; i<n; ++i){
        mini[i]=min(mini[i-1], v[i]);
     }
     maxi[n-1]=v[n-1];
     for(lli i=n-2; i>=0; --i){
        maxi[i]=max(maxi[i+1], v[i]);
     }
     vector<lli> cur (n);
     lli s2=0;
     for(lli i=0; i<n-1; ++i){
        s2+=v[i];
        lli aux=max(s2, s2+maxi[i+1]-mini[i]);
        cur[i]=aux;
     }
     cur[n-1]=s;
     h%=s;
     ans++;
     lli ind=0;
     while(cur[ind]<h){
        ind++;
        ans++;
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