    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
  //  #define endl '\n'
    using ld=long double;
    lli x,y,z,k;
    ld fn(lli val){
        if(val<=0) return 1e15;
        lli a=val/k;
        lli b=val%k;
        ld ans1=x*val;
        ld aux=(a*(a+1))/2;
        aux*=k;
        aux=z-aux;
        aux/=val;
        aux*=y;
        ld ans3=a*y;
        ans1+=aux+ans3;
        return ans1;
    }
    lli fn2(lli val){
        if(val<=0) return 1e15;
        lli a=val/k;
        lli b=val%k;
        lli ans1=x*val;
        lli aux=(a*(a+1))/2;
        aux*=k;
        aux=z-aux;

        aux=ceil( (ld) aux/val);
       // deb(aux);
        aux*=y;
        lli ans3=a*y;
        ans1+=aux+ans3;
        return ans1;
    }
    void solve(){
        cin>>x>>y>>z>>k;
        ld l=0;
        ld r=(k+1)*2*sqrt(z);
        while(r-l >=1e-10){
            ld mid1=l+(r-l)/3;
            ld mid2=mid1+(r-l)/3;
            ld a=fn(mid1);
            ld b=fn(mid2);
       /*     deb(l);
            deb(r);
            deb(mid1);
            deb(mid2);
            deb(a);
            deb(b);*/
            if(a<b) r=mid2;
            else l=mid1;
        }
        lli a=l;
        lli ant=fn2(a);
        lli ind=a-1;
        while(ind>0){
            lli act=fn2(ind);
            if(act<ant){
                ant=act;
                ind--;
            }
            else break;
        }
        
        lli ans=ant;
        lli c=a/k;
        lli ayuda=z-k*(((c)*(c+1))/2);
        //deb(ayuda);
        lli div=ceil(ayuda/a);
        //deb(div);
        if(div!=0){
        lli xd=ayuda/div;
        ans=min(ans, fn2(xd));
        ans=min(ans, fn2(xd-1));
        ans=min(ans, fn2(xd+1));
        }
        if(div!=1){
        lli xd=ayuda/(div-1);
        ans=min(ans, fn2(xd));
        ans=min(ans, fn2(xd-1));
        ans=min(ans, fn2(xd+1));
        }

        lli xd=ayuda/(div+1);
        ans=min(ans, fn2(xd));
        ans=min(ans, fn2(xd-1));
        ans=min(ans, fn2(xd+1));

        lli ant2=fn2(xd);
        ind=xd-1;
        while(ind>0){
            lli act=fn2(ind);
            if(act<ant2){
                ant2=act;
                ind--;
            }
            else break;
        }
        ans=min(ans, ant2);
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