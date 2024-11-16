    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> p (n+1);
        for(lli i=1; i<=n; ++i){
            cin>>p[i];
        }
        bool pos=true;
        for(lli i=1; i<=n; ++i){
            if(p[i]==i) continue;
            if(p[i+1]==i){
                if(p[i]==i+1){
                    i++;
                }
                else{
                    pos=false;
                    break;
                }
            }
            else{
                pos=false;
                break;
            }
        }
        if(pos){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
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