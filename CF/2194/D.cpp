    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m;
        cin>>n>>m;
        vector<vector<lli>> v (n, vector<lli> (m));
        lli s=0;
        for(lli i=0; i<n; ++i){
            for(lli j=0; j<m; ++j){
                cin>>v[i][j];
                s+=v[i][j];
            }
        }

        vector<lli> h (m,n);
        lli c=0;
        lli ind=0;
        while(c<s/2){
            if(h[ind]>0){
                h[ind]--;
                c+=v[h[ind]][ind];
            }
            else{
                ind++;
            }
        }
        string ans="";
        lli act=0;
        for(lli i=0; i<m; ++i){
            while(act<h[i]){
                ans+='D';
                act++;
            }
            ans+='R';
        }
        while(act<n){
            ans+='D';
            act++;
        }
        lli val=c*(s-c);
        cout<<val<<endl;
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