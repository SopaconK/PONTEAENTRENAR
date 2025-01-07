    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> l (n);
        vector<lli> r (n);
        for(lli i=0; i<n; ++i){
            cin>>l[i]>>r[i];
        }
        vector<lli> pos (1e5+5,0);
        for(lli i=0; i<n; ++i){
            if(l[i]==r[i]){
                pos[l[i]]++;
            }
        }
        vector<lli> right (1e5+5,0);
        for(lli i=1e5; i>=0; --i){
            if(pos[i+1]!=0){
                right[i]=right[i+1];
            }
            else{
                right[i]=i;
            }
        }
        vector<bool> ans (n,0);
        for(lli i=0; i<n; ++i){
            if(l[i]==r[i]){
                if(pos[l[i]]==1){
                    ans[i]=1;
                }
                else ans[i]=0;
            }
            else{
                if(pos[l[i]]==0 || right[l[i]]<r[i]) ans[i]=1;
                else ans[i]=0;
            }
        }
        for(lli i=0; i<n; ++i){
            if(ans[i]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
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