    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli b,c,d;
        cin>>b>>c>>d;
        bool p=0;
        lli ans=0;
        lli pow=1;
        while(b>0 || c>0 || d>0){
            if(c%2==0){
                if(b%2==0){
                    if(d%2==0){
                        if(p){
                            ans+=pow;
                            p=0;
                        }
                        else{
                            p=0;
                        }
                    }
                    else{
                        if(p){
                            p=1;
                        }
                        else{
                            ans+=pow;
                            p=0;
                        }
                    }
                }
                else{
                    if(d%2==0){
                        if(p){
                            p=0;
                        }
                        else{
                            cout<<-1<<endl;
                            return;
                        }
                    }
                    else{
                        if(p){
                            cout<<-1<<endl;
                            return;
                        }
                        else{
                            p=0;
                        }
                    }
                }
            }
            else{
                if(b%2==0){
                    if(d%2==0){
                        if(p){
                            cout<<-1<<endl;
                            return;
                        }
                        else{
                            p=0;
                        }
                    }
                    else{
                        if(p){
                            p=1;
                        }
                        else{
                            cout<<-1<<endl;
                            return;
                        }
                    }
                }
                else{
                    if(d%2==0){
                        if(p){
                            p=0;
                        }
                        else{
                            ans+=pow;
                            p=0;
                        }
                    }
                    else{
                        if(p){
                            ans+=pow;
                            p=1;
                        }
                        else{
                            p=0;
                        }
                    }
                }
            }
            b/=2;
            c/=2;
            d/=2;
            pow*=2;
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