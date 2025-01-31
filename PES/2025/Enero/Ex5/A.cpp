    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    lli MOD=1e9+7;

    lli binexp(lli b, lli e){
        if(e==0) return 1ll;
        if(e==1) return b%MOD;
        lli x=binexp(b,e/2);
        x*=x;
        x%=MOD;
        if(e%2){
            x*=b;
            x%=MOD;
        }
        return x;
    }

    void solve(){
        lli h,w;
        cin>>h>>w;
        if(w>h){
        vector<lli> aux (h+1,0);
        aux[0]=1;
        aux[1]=1;
        for(lli i=2; i<=h; ++i){
            aux[i]=aux[i-1]+aux[i-2];
            aux[i]%=MOD;
        }
        for(lli i=1; i<=h; ++i){
            aux[i]=binexp(aux[i], w);
        }
        vector<lli> ans(h+1,0);
        for(lli x=0; x<=h; ++x){
      //      deb(x);
            ans[x]=aux[x];
        //    deb(ans[x]);
            for(lli i=1; i<x; ++i){
                ans[x]-=ans[i]*aux[x-i];
          //      deb(ans[x]);
                ans[x]%=MOD;
            //    deb(ans[x]);
                ans[x]+=MOD;
                ans[x]%=MOD;
            }
           // deb(ans[x]);
        }
        cout<<ans[h]<<endl;
        }
        else{
            vector<vector<lli>> comb (w+1, vector<lli> (w+1, 0));
            comb[0][0]=1;
            for(lli i=1; i<=w; ++i){
                comb[i][0]=1;
                for(lli j=1; j<=w; ++j){
                    comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
                    comb[i][j]%=MOD;
                    
                }
            }

            vector<lli> f1 (w+1,0);
            vector<lli> f2(w+1,0);
            bool b=1;
            for(lli i=1; i<=w; ++i){
                f1[i]=comb[w][i];
            }

            for(lli i=1; i<h-1; ++i){
                if(b){
                for(lli j=1; j<=w; ++j){
                    f2[j]=0;
                    for(lli k=1; k<=w-j; ++k){
                        f2[j]+=f1[k]*comb[w-k][j];
                        f2[j]%=MOD;
                    }
                }
                }
                else{
                    for(lli j=1; j<=w; ++j){
                    f1[j]=0;
                    for(lli k=1; k<=w-j; ++k){
                        f1[j]+=f2[k]*comb[w-k][j];
                        f1[j]%=MOD;
                    }
                }
                }
                b=!b;
            }
            lli ans=0;
            if(b){
                for(lli i=1; i<=w; ++i){
                    ans+=f1[i];
                    ans%=MOD;
                }
            }
            else{
                 for(lli i=1; i<=w; ++i){
                    ans+=f2[i];
                    ans%=MOD;
                }
                
            }
            cout<<ans<<endl;



        }

        
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
      //  cin>>t;
        while(t--){
            solve();
        }
    }