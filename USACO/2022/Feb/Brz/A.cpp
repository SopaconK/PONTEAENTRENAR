    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    using ld=long double;

    void solve(){
        lli n;
        cin>>n;
        vector<lli> a (n);
        lli sum=0;
        for(lli i=0; i<n; ++i){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum==0){
            cout<<0<<endl;
            return;
        }
        lli ans=1e9;
        for(lli i=1; i<=sum; ++i){
            if(sum%i !=0) continue;
            lli ind=1;
            lli cont=0;
            lli aux=a[0];
            bool pos=true;
            while(ind<n){
                while(aux<i){
                    if(ind>=n) break;
                    aux+=a[ind];
                    ind++;
                    cont++;
                }
                if(aux!=i){
                    pos=false;
                    break;
                }
                else{
                    if(ind<n){
                        aux=a[ind];
                        ind++;
                    }
                }
            }
            if(pos){
                ans=min(ans, cont);
            }
        }
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