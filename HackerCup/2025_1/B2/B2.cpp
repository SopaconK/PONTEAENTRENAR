#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define endl '\n'
#define deb(x) cout<<#x<<": "<<x<<endl;
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

map<pair<lli,lli>, lli> coef;


lli binom(lli x, lli y){
    if(coef.find({x,y})!=coef.end()) return coef[{x,y}];
    if(y>x-y) return binom(x, x-y);
    
    lli ans=1;

    for(lli i=x-y+1; i<=x; ++i){
        lli xd=i%MOD;
        ans*=xd;
        ans%=MOD;
    }

    for(lli i=1; i<=y; ++i){
        ans*=binexp(i, MOD-2);
        ans%=MOD;
    }
    return coef[{x,y}]=ans;

}


vector<lli> primes;

void criba(){
    vector<bool> nums (1e7+5,1);
    for(lli i=2; i<nums.size(); ++i){
        if(nums[i]){
            primes.pb(i);
            for(lli j=i*i; j<nums.size(); j+=i){
                nums[i]=0;
            }
        }
    }
}

lli n;
void dfs(vector<lli> & v, lli &num, vector<lli> &meta, vector<lli> &prim, map<lli,lli> &mp){
    
    
    
    lli ans=1;

    for(lli i=0; i<v.size(); ++i){
        ans*=binom(n-1+v[i], v[i]);
        ans%=MOD;
    }

    
    mp[num]=ans;
    
    
    bool mov=0;
    for(lli i=0; i<v.size(); ++i){
        if(v[i]==meta[i]){
            while(v[i]){
                num/=prim[i];
                v[i]--;
            }
        }
        else{
            v[i]++;
            mov=true;
            num*=prim[i];

            break;
        }
    }
    if(mov){
        dfs(v, num, meta, prim, mp);
    }
}


void solve(lli t){
    lli ans=0;
    lli a,b;
    cin>>n>>a>>b;
    lli baux=b;
    vector<lli> meta;
    vector<lli> prim;
    for(lli x: primes){
        if(baux%x==0){
            meta.pb(0);
            prim.pb(x);
        }
        while(baux%x==0){
            meta[meta.size()-1]++;
            baux/=x;
        }
    }
    if(baux>1){
        meta.pb(1);
        prim.pb(baux);
    }


    vector<lli> v (meta.size(), 0);
    map<lli,lli> mp;
    lli num=1;
    dfs(v, num, meta, prim, mp);
    
     for(auto x: mp){
        if(x.first<=a){
            lli aux=mp[x.first]*mp[b/x.first];
            aux%=MOD;
            ans+=aux;
            ans%=MOD;
        }
    }

    cout<<"Case #"<<t<<": "<<ans<<endl;   
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    criba();
    lli t=1;
    cin>>t;
    for(lli i=1; i<=t; ++i) solve(i);
}