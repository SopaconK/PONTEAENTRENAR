    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m;
        cin>>n>>m;
        bool ans=0;
        if(n==m){
            cout<<"YES"<<endl;
            return;
        }
        lli mx=1;
        while(true){
            if(n%3!=0) break;
            n/=3;
            mx*=2;
            if(m%n==0){
                lli d=m/n;
                if(d<=mx){
                    lli pos=1;
                    while(d>1){
                        if(d%2==0){
                            d/=2;
                        }
                        else{
                            pos=0;
                            break;
                        }
                    }
                    if(pos){
                        cout<<"YES"<<endl;
                        return;
                    }
                }
                else{
                    break;
                }
            }
        }
        cout<<"NO"<<endl;
        return;
        
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