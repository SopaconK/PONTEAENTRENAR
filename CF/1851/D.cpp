    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> a (n);
        vector<lli> v (n+1,0);
        lli masgrande=-1;
        lli ant=0;
        for(lli i=0; i<n-1; ++i){
            cin>>a[i];
        }
        for(lli i=0; i<n-1; ++i){
           
            if(a[i]-ant >n){
                if(masgrande!=-1){
                    cout<<"NO"<<endl;
                    return;
                }
                masgrande=a[i]-ant;
            }
            else{
                v[a[i]-ant]++;
            }
            ant=a[i];
        }
        lli sum=0;
        for(lli i=1; i<=n; ++i){
            if(v[i]==1) sum++;
        }
        if(sum==n-1){
            cout<<"YES"<<endl;
            return;
        }
        
        lli f1=-1;
        lli f2=-1;
        for(lli i=1; i<=n; ++i){
            if(v[i]==0){
                if(f1==-1){
                    f1=i;
                }
                else{
                    if(f2==-1){
                        f2=i;
                    }
                    else{
                        cout<<"NO"<<endl;
                        return;
                    }
                }
            }
            else if(v[i]!=1){
                if(masgrande!=-1){
                    cout<<"NO"<<endl;
                    return;
                }
                masgrande=i;
            }
        }
        if(f2==-1){
            cout<<"NO"<<endl;
            return;
        }
        if(masgrande==-1){
            cout<<"NO"<<endl;
            return;
        }
        if(masgrande==f1+f2){
            cout<<"YES"<<endl;
            return;
        }
        cout<<"NO"<<endl;
        return;
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