    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    lli sum(lli x){
        lli ans=0;
        while(x){
            ans+=x%10;
            x/=10;
        }
        return ans;
    }

    void solve(){
        for(lli i=1; i<=10000; ++i){
            if(i%sum(i)==0 && (i+1)%sum(i+1)==0){
                cout<<i<<" ";
            }
        }
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
      //  cin>>t;
        while(t--){
            solve();
        }
    }