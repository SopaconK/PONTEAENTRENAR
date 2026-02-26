    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    vector<lli> v ={10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111, 100000};
    vector<bool> dp;
    void prec(){
        dp.resize(1e5+5,0);
        dp[1]=1;
        for(lli x: v){
            for(lli i=1; i<dp.size(); ++i){
                if(!dp[i]) continue;
                lli val=x*i;
                if(val<dp.size()){
                    dp[val]=1;
                }
                else{
                    break;
                }
            }
        }
    }
    void solve(){
        lli n;
        cin>>n;
       
        if(!dp[n]){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
        prec();
        cin>>t;
        while(t--){
            solve();
        }
    }