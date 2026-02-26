    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    vector<lli> criba;

    void hacercriba(){
        vector<bool> nums (1e3+5, 1 );
        for(lli i=2; i<nums.size(); ++i){
            if(!nums[i]) continue;
            criba.pb(i);
            for(lli j=i*i; j<nums.size(); j+=i) nums[j]=0;
        }
    }

    void solve(){
        lli x;
        cin>>x;
        lli ans=1;
        for(lli p: criba){
            lli cont=0;
            while(x%p==0){
                cont++;
                x/=p;
            }
            ans*=(cont+1);
        }
        if(x>1){
            ans*=2;
        }


        cout<<ans<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        hacercriba();
        int t=1;
        cin>>t;
        while(t--){
            solve();
        }
    }