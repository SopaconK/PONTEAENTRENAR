    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli x,y;
        cin>>y>>x;
        if(x>=y){
            if(x%2==0){
                cout<<(x-1)*(x-1)+y<<endl;
                return;
            }
            else{
                cout<<x*x+1-y<<endl;
            }
        }
        else{
            if(y%2==0){
                cout<<y*y+1-x<<endl;
            }
            else{
                cout<<(y-1)*(y-1)+x<<endl;
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