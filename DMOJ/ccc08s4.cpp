    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
//    #define endl '\n'


    lli op(lli a, lli b, lli t){
        if(t==0){
            return a-b;
        }
        if(t==1){
            return a+b;
        }
        if(t==2){
            return a*b;
        }
        if(t==3){
            if(b>0) if(a%b==0) return a/b;
        }
        return -1e15;
    }

    lli dos(lli a, lli b){
        lli ans=-1e10;
//         deb("dosini");
  //      deb(a);
    //    deb(b);
        for(lli t=0; t<4; ++t){
            lli x=op(a,b,t);
            if(x<=24){
                ans=max(ans,x);
            }
            x=op(b,a,t);
            if(x<=24){
                ans=max(ans,x);
            }
        }
//        deb("dos");
  //      deb(a);
    //    deb(b);
      //  deb(ans);
        return ans;
        
    }

    lli tres(lli a, lli b, lli c){
//     deb("tresini");
  //      deb(a);
    //    deb(b);
      //  deb(c);
        lli ans=-1e10;
        
        for(lli t=0; t<4; ++t){
            lli x=op(a,b,t);
            if(x>-300000){
                ans=max(ans, dos(x,c));
            }
            x=op(b,a,t);
            if(x>-300000){
                ans=max(ans, dos(x,c));
            }
            swap(b,c);
            x=op(a,b,t);
            if(x>-3000000){
                ans=max(ans, dos(x,c));
            }
            x=op(b,a,t);
            if(x>-3000000){
                ans=max(ans, dos(x,c));
            }
            swap(a,c);
            x=op(a,b,t);
            if(x>-3000000){
                ans=max(ans, dos(x,c));
            }
            x=op(b,a,t);
            if(x>-3000000){
                ans=max(ans, dos(x,c));
            }
        }
 //       deb("tres");
   //     deb(a);
     //   deb(b);
       // deb(c);
      //  deb(ans);
        return ans;
    }

    lli cuatro(lli a,lli b,lli c,lli d){
           vector<lli> v (4);
        v[0]=a;
        v[1]=b;
        v[2]=c;
        v[3]=d;
        lli ans=-1e10;
        sort(v.begin(), v.end());
        do{
            for(lli t=0; t<4; ++t){
                lli x=op(v[0],v[1],t);
                if(x>-3000000){
                ans=max(ans, tres(x,v[2], v[3]));
                }
                x=op(v[1],v[0],t);
                if(x>-3000000){
                ans=max(ans, tres(x,v[2], v[3]));
                }
            }
        }while(next_permutation(v.begin(), v.end()));
        return ans;
    }

    void solve(){
        vector<lli> v (4);
        for(lli i=0; i<4; ++i) cin>>v[i];
        cout<<cuatro(v[0], v[1], v[2], v[3])<<endl;
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