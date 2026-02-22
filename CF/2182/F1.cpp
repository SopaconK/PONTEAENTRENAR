    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
   // #define endl '\n'
    const lli MOD=998244353;

    lli binexp(lli n, lli p){
        if(p==0) return 1ll;
        if(p==1) return n%MOD;
        lli a=binexp(n, p/2);
        a*=a;
        a%=MOD;
        if(p%2){
            a*=n;
            a%=MOD;
        }
        return a;
    }

    

    void solve(){
        lli n,m;
        cin>>n>>m;
        vector<lli> v (61, 0);
        for(lli i=0; i<n; ++i){
            lli c;
            cin>>c;
            v[c]++;
        }

        while(m--){
            lli t,x;
            cin>>t>>x;
    //        deb(t);
      //      deb(x);
            if(t==1){
                n++;
                v[x]++;
            }
            if(t==2){
                n--;
                v[x]--;
            }
            if(t==3){
                vector<bool> k;
                while(x>0){
                    if(x%2) k.pb(1);
                    else k.pb(0);
                    x/=2;
                }
                lli ans=0;
                /*vector<lli> sum(61,0);
                sum[60]=v[60];
                for(lli i=59; i>=0; --i) sum[i]=sum[i+1]+v[i];*/
                lli s=0;
                lli n2=n;
                lli mult=1;
                for(lli i=60; i>=0; --i){
                    if(i>=k.size()){
                        lli aux=(binexp(2,v[i])-1+MOD)%MOD;
                        aux*=(binexp(2, n2-v[i]));
                        aux%=MOD;
                        ans+=aux;
                        ans%=MOD;
                        n2-=v[i];
                    }
                    else{
                        if(k[i]){
                            if(v[i]>1){
                            lli aux=(binexp(2,v[i])-1-v[i]+MOD)%MOD;
                            aux*=(binexp(2, n2-v[i]));
                            aux%=MOD;
                            aux*=mult;
                            ans%=MOD;
                            ans+=aux;
                            ans%=MOD;
                            n2-=v[i];
                            }
                            mult*=v[i];
                            mult%=MOD;
                        }
                        else{
                            lli aux=(binexp(2,v[i])-1+MOD)%MOD;
                                aux*=(binexp(2, n2-v[i]));
                                aux%=MOD;
                                aux*=mult;
                                aux%=MOD;
                                ans+=aux;
                                
                                ans%=MOD;
                                n2-=v[i];
                        }
                    }

                }

                cout<<ans<<endl;
            }
        }
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
    //    cin>>t;
        while(t--){
            solve();
        }
    }