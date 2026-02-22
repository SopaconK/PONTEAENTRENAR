    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli a,b;
        cin>>a>>b;
        lli ans=0;

        lli x=a;
        lli y=b;
        lli aux=1;
        lli ind=0;
        bool st=0;
        while(true){
            if(st){
                if(y>=aux){
                   
                    ind++;
                    y-=aux;
                     aux*=2;
                }
                else{
                    break;
                }
            }
            else{
                if(x>=aux){
                    
                    ind++;
                    x-=aux;
                    aux*=2;
                }
                else break;
            }
            st=!st;
        }
        ans=max(ans, ind);
        x=a;
        y=b;
        aux=1;
        ind=0;
        st=1;
         while(true){
            if(st){
                if(y>=aux){
                   ind++;
                    y-=aux;
                    aux*=2;
                }
                else{
                    break;
                }
            }
            else{
                if(x>=aux){
                   ind++;
                    x-=aux;
                    aux*=2;
                }
                else break;
            }
            st=!st;
        }
        ans=max(ans, ind);
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