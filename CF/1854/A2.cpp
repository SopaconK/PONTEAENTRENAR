    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    void solve_neg (vector<lli> &a, vector<pair<lli,lli>> &ans){
        for(lli i=a.size()-2; i>0; --i){
            if(a[i]>a[i+1]){
                a[i]+=a[i+1];
                ans.pb({i,i+1 });
            }
        }
    }

    void solve_pos(vector<lli> &a, vector<pair<lli,lli>> & ans){
        for(lli i=2; i<a.size(); ++i){
            if(a[i]<a[i-1]){
                a[i]+=a[i-1];
                ans.pb({i,i-1});
            }
        }
    }

    void solve(){
        lli n;
        cin>>n;
        vector<lli> a (n+1);
        lli maxi=-100;
        lli p1=0;
        lli mini=100;
        lli p2=0;
        for(lli i=1; i<=n; ++i){
            cin>>a[i];
           if(a[i]>maxi){
            maxi=a[i];
            p1=i;
           }
            if(a[i]<mini){
                mini=a[i];
                p2=i;
            }
        }

        if(mini>=0){
            vector<pair<lli,lli>> ans;
            solve_pos(a,ans);
            cout<<ans.size()<<endl;
            for(auto si: ans){
                cout<<si.first<<" "<<si.second<<endl;
            }
            return;
        }
        if(maxi<=0){
            vector<pair<lli,lli>> ans;
            solve_neg(a,ans);
            cout<<ans.size()<<endl;
            for(auto si: ans){
                cout<<si.first<<" "<<si.second<<endl;
            }
            return;
        }

        vector<lli> a2=a;
        //Haciendo todos pos
        vector<pair<lli,lli>> ans;
       while(maxi<-mini){
        a[p1]*=2;
        maxi*=2;
        ans.pb({p1,p1});
       }
       for(lli i=1; i<=n; ++i){
        if(a[i]<0){
            a[i]+=maxi;
            ans.pb({i, p1});
        }
       }
       solve_pos(a,ans);

       //Haciendo todos neg
       a=a2;
       maxi=a[p1];
       vector<pair<lli,lli>> ans2;
        while(-mini<maxi){
            a[p2]*=2;
            mini*=2;
            ans2.pb({p2,p2});
        }
        for(lli i=1; i<=n; ++i){
            if(a[i]>0){
                a[i]+=mini;
                ans2.pb({i, p2});
            }
        }
        solve_neg(a, ans2);


        if(ans.size()<=ans2.size()){
            cout<<ans.size()<<endl;
            for(auto si: ans){
                cout<<si.first<<" "<<si.second<<endl;
            }
        }
        else{
            cout<<ans2.size()<<endl;
            for(auto si: ans2){
                cout<<si.first<<" "<<si.second<<endl;
            }
            
        }
       

        
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