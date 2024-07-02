    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    lli solve(string &a, string &b, lli i, lli j, bool s){ //s=0 si no has tocado a, 1 si ya
        
        if(i>=a.size() || j>=b.size()) return max(0ll, (lli) b.size()-j);
        if(s){
            lli ax=-1;
            for(lli x=i; x<a.size(); ++x){
                if(a[x]==b[j]){
                    ax=x;
                    break;
                }
            }
            if(ax==-1) return solve(a,b,a.size(), j, s);
            return solve(a,b,ax+1, j+1, s);
        }
        else{
            lli ans=solve(a,b,i,j,1);
            ans=min(ans, 1+solve(a,b,i,j+1,0));
            return ans;
        }
        return 0;
    }

    void solve(){
        string a,b;
        cin>>a>>b;
        lli ans=solve(a,b,0,0,0)+a.size();
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