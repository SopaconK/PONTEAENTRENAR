    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    lli MOD=998244353;
    lli binexp(lli x, lli p){
    
        if(p==0) return 1ll;
        if(p==1) return x%MOD;
        lli a=binexp(x, p/2);
        a*=a;
        a%=MOD;
        if(p%2) a*=x;
        return a%=MOD;
    }

    lli inv(lli a){
        return binexp(a, MOD-2);
    }

    void solve(){
        lli n,q;
        cin>>n>>q;
        vector<lli> a (n+1, 0);
        vector<lli> b(n+1,0);
        for(lli i=1; i<=n; ++i){
            cin>>a[i];
        }
        for(lli i=1; i<=n; ++i){
            cin>>b[i];
        }
        map<lli,lli> useda;
        map<lli,lli> usedb;
        vector<lli> a2=a;
        vector<lli> b2=b;
        sort(a2.begin(), a2.end());
        sort(b2.begin(), b2.end());
        lli ans=1;
        for(lli i=1; i<=n; ++i){
            ans*=min(a2[i], b2[i]);
            ans%=MOD;
            useda[a2[i]]=i;
            usedb[b2[i]]=i;
        }

        cout<<ans<<" ";
        while(q--){
            lli o,x;
            cin>>o>>x;
 /*           cout<<endl;
            for(lli i=1; i<=n; ++i){
                cout<<a2[i]<<" ";
            }
            cout<<endl;
            for(lli i=1; i<=n; ++i){
                cout<<b2[i]<<" ";
            }
            cout<<endl;*/
            if(o==1){
                lli aux=a[x];
                a[x]++;
                lli aux2=useda[aux];
   //             deb(aux);
     //           deb(aux2);
                ans*=inv(min(a2[aux2], b2[aux2]));
                ans%=MOD;
                a2[aux2]++;
                ans*=min(a2[aux2], b2[aux2]);
                ans%=MOD;
                if(a2[aux2-1]==aux){
                    useda[aux]--;
                }
                else useda[aux]=0;
                if(useda[aux+1]==0) useda[aux+1]=aux2;
            }
            else{
                lli aux=b[x];
                b[x]++;
                lli aux2=usedb[aux];
       //          deb(aux);
         //       deb(aux2);
                ans*=inv(min(a2[aux2], b2[aux2]));
                ans%=MOD;
                b2[aux2]++;
                ans*=min(a2[aux2], b2[aux2]);
                ans%=MOD;
                if(b2[aux2-1]==aux){
                    usedb[aux]--;
                }
                else usedb[aux]=0;
                if(usedb[aux+1]==0) usedb[aux+1]=aux2;
            }
            cout<<ans<<" ";
        }
        cout<<endl;


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