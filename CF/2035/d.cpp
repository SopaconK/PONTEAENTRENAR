    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    lli MOD=1e9+7;


    lli binexp(lli b, lli p){
        if(p==0) return 1ll;
        if(p==1) return b%MOD;
        lli x=binexp(b, p/2);
        x*=x;
        x%=MOD;
        if(p%2){
            x*=b;
            x%=MOD;
        }
        return x;
    }
    void solve(){
        lli n;
        cin>>n;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }
        lli sum=v[0];
        vector<lli> im(n);
        vector<lli> dos (n,0);
        
        for(lli i=0; i<n; ++i){
    
            while(v[i]%2==0){
                dos[i]++;
                v[i]/=2;
            }
            im[i]=v[i];
        }
        stack<lli> sk;
        sk.push(0);
        cout<<sum<<" ";
        for(lli i=1; i<n; ++i){
            sum+=(im[i]*binexp(2, dos[i]))%MOD;
            sum%=MOD;
            sk.push(i);
            while(sk.size()>1){
                lli x=sk.top();
                sk.pop();
                lli y=sk.top();
                sk.pop();
                lli a=im[x];
                lli b=0;
                lli c=im[y];
                bool may=false;
                while(b<=dos[x]){
                    if(a>=c){
                        may=true;
                        break;
                    }
                    b++;
                    a*=2;
                }
          //      deb(x);
            //    deb(y);
              //  deb(may);
                if(may){
                    sum-=(im[y]*binexp(2, dos[y]))%MOD;
                    sum+=im[y];
                    sum%=MOD;
                    sum+=MOD;
                    sum%=MOD;
                    sum-=(im[x]*binexp(2, dos[x]))%MOD;
                    sum+=(im[x]*binexp(2, dos[y]+dos[x]))%MOD;
                    sum%=MOD;
                    sum+=MOD;
                    sum%=MOD;
                    dos[x]+=dos[y];
                    dos[y]=0;
                    sk.push(x);
                }
                else{
                    sk.push(y);
                    sk.push(x);
                    break;
                }
            }
            cout<<sum<<" ";
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