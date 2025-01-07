    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,d;
        cin>>n>>d;
        string s;
        cin>>s;
        n+=d;
        for(char c: s){
            if(c=='@'){
                n--;
            }
        }
        cout<<n<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
     //   cin>>t;
        while(t--){
            solve();
        }
    }