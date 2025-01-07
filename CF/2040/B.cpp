    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        
        lli ans=0;
        while(n>0){
            if(n==1){
                ans++;
                break;
            }
            if(n==2){
                ans+=2;
                break;
            }
            lli xd= (n+1)/2;
            ans++;
            xd--;
            n=xd;
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