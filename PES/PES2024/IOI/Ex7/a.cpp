    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    using ld=long double;

    
    struct Line{
        ld m;
        ld b;
        lli ind;
        ld eval(ld x) {
            return m*x+b;
        }
        ld intersect (Line l){
            return (ld) (l.b-b)/(m-l.m);
        }

    };

    vector<ld> dp;
    vector<ld> cnt;

    void slv(lli n, ld m){
        deque<Line> dq;
        dp[n]=0;
        cnt[n]=0;
       // deb(m);
        dq.push_back({1.0/n, 1-m, n});
        for(lli i=n-1; i>=0; --i){
            dp[i]=0;
            cnt[i]=0;
           // deb(i);
            if(dq.size()>1){
               // deb(dq[0].eval(-i));
             //   deb(dq[1].eval(-i));
            }
            while(dq.size()>1 && dq[0].eval(-i) < dq[1].eval(-i)){
                dq.pop_front();
            }
            lli id=dq[0].ind;
            dp[i]=dq[0].eval(-i);
            cnt[i]=cnt[id]+1;
         //   deb(i);
           // deb(dp[i]);
            if(i!=0){
                Line l={1.0/i, 1+dp[i]-m, i};
                while(dq.size()>1 && dq.back().intersect(l)< dq.back().intersect(dq[dq.size()-2])){
                    dq.pop_back();
                }
                dq.push_back(l);
            }
        }
    }

    void solve(){
        lli n,k;
        cin>>n>>k;
        dp.resize(n+1,0);
        cnt.resize(n+1,0);
        ld l=0;
        ld r=1;
        ld ans;
        slv(n,0);
       // deb(dp[0]);
        //deb(cnt[0]);
        ans=dp[0]+(ld) cnt[0]*0;
      //  deb(ans);
        slv(n,1);
    //    deb(dp[0]);
  //      deb(cnt[0]);
        ans=dp[0]+(ld) cnt[0]*1;
//        deb(ans);
        const ld cot=1e-12;
        while(r-l >cot){
            ld m=(l+r)/2;
            slv(n,m);
         //   deb(m);
       //     deb(dp[0]);
     //       deb(cnt[0]);
            ld ans=dp[0]+(ld) cnt[0]*m;
   //         deb(ans);
            if(cnt[0]>k){
                l=m;
            }
            else{
                if(cnt[0]==k){
                    l=m;
                    break;
                }
                r=m;
            }
        }

         ans=dp[0]+(ld) cnt[0]*l;
        cout<<setprecision(9)<<fixed<<ans<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        lli t=1;
     //   cin>>t;
        while(t--){
            solve();
        }
    }