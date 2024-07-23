    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    using ld=long double;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> v(n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }
        lli init=0;
        while(init < n && v[init]==1){
            init++;
        }
    //    deb(init);
        if(init==n){
            cout<<0<<endl;
            return;
        }
        for(lli i=init; i<n; ++i){
            if(v[i]==1){
                cout<<-1<<endl;
                return;
            }
        }

        vector<ld> v1 (n);
        for(lli i=init; i<n; ++i){
            v1[i]=log2( (ld) v[i]);
        }
        vector<ld> v2 (n);
        for(lli i=init; i<n; ++i){
            v2[i]=log2( (ld) v1[i]);
        //    deb(v2[i]);
        }
        lli ans=0;
        ld ant=v2[init];
        for(lli i=init+1; i<n; ++i){
            if(v2[i]<ant){
                while(v2[i]+1000<ant){
                    v2[i]+=1000;
                    ans+=1000;
                }
              
                
                while(v2[i]<ant){
                    v2[i]+=1.0;
                    ans++;
                }
            }
            ant=v2[i];
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