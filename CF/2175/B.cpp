    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,l,r;
        cin>>n>>l>>r;
        vector<lli> ans (n);
        ans[0]=1;
        lli ant=1;
        l--;
        r--;
        for(lli i=1; i<n; ++i){
            if(i==r){
                ans[i]=ant^(l);
                ant=l;
            }
            else{
                ans[i]=(i+1)^(ant);
                ant=i+1;
            }
        }
        for(lli i=0; i<n; ++i){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
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