    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        if(n%2==0){
            while(n>2){
                cout<<"33";
                n-=2;
            }
            cout<<"66";
            cout<<endl;
        }
        else{
            if(n<=3){
                cout<<-1<<endl;
            }
            else{
                while(n>5){
                    cout<<"33";
                    n-=2;
                }
                cout<<"36366"<<endl;
            }
        }
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