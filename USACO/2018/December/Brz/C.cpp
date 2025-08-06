    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    using ld=long double;

    vector<lli> val (20);
    set<lli> ans;

    void bt (lli x, lli step, vector<bool> &st){
        if(step==5){
      //      cout<<x<<endl;
            ans.insert(x);
            return;
        }
        if(step%2){
            for(lli i=0; i<20; ++i){
                if(st[i]){
                    st[i]=0;
                    bt(x-val[i],step+1, st);
                    st[i]=1;
                }
            }
        }
        else{
            for(lli i=0; i<20; ++i){
                if(!st[i]){
                    st[i]=1;
                    bt(x+val[i],step+1, st);
                    st[i]=0;
                }
            }
        }
    }

    void solve(){
        for(lli i=0; i<20; ++i){
            cin>>val[i];
        }
        vector<bool> st(20,0);
        for(lli i=0; i<10; ++i) st[i]=1;
        bt(1000, 1, st);

        
        cout<<ans.size()<<endl;
    }




    int main(){
        freopen("backforth.in", "r", stdin);
        freopen("backforth.out", "w", stdout);
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
 //       cin>>t;
        while(t--){
            solve();
        }
    }