    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    bool check(vector<bool> &v1, vector<bool> &v2, lli c){
        lli x=0;
        for(lli i=0; i<v1.size(); ++i){
            if(v2[i]) x+=c;
            if(v1[i]){
                if(x<=0){
                    return false;
                }
                x--;
            }
            x/=2;
        }
        return true;
    }

    void solve(){
        lli s,m;
        cin>>s>>m;
        vector<bool> v1;
        vector<bool> v2;
        while(s>0 || m>0){
            v1.pb(s%2);
            v2.pb(m%2);
            s/=2;
            m/=2;
        }
        for(lli i=0; i<v1.size(); ++i){
            if(v1[i]){
                if(!v2[i]){
                    cout<<-1<<endl;
                    return;
                }
                break;
            }
            if(v2[i]) break;
        }
        lli l=0;
        lli r=1e18+1;
        while(l!=r){
            lli m=(l+r)/2;
            if(check(v1,v2,m)){
                r=m;
            }
            else{
                l=m+1;
            }
        }
        cout<<r<<endl;
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