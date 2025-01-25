    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }
        vector<lli> a (64,0);
        vector<lli> b (64,0);
        vector<lli> c (64,0);
        vector<lli> d (64,0);
        vector<bool> ans (64,0);
        for(lli i=0; i<n; ++i){
            vector<lli> x (64,0);
            lli aux=v[i];
            bool ant=0;
            for(lli j=0; j<64; ++j){
                if(aux%2){
                    if(ant){
                        x[j]=3;
                    }
                    else{
                        x[j]=2;
                    }
                }
                else{
                    if(ant){
                        x[j]=1;
                    }
                    else{
                        x[j]=0;
                    }
                }
                ant=aux%2;
                aux/=2;
                if(x[j]==0){
                    a[j]++;
                    if((c[j]+d[j])%2){
                        ans[j]=!ans[j];
                    }
                }
                else if(x[j]==1){
                    b[j]++;
                    if((b[j]+c[j])%2){
                        ans[j]=!ans[j];
                    }
                }
                else if(x[j]==2){
                    c[j]++;
                     if((a[j]+b[j])%2){
                         ans[j]=!ans[j];
                     }
                }
                else{
                    d[j]++;
                     if((a[j]+d[j])%2){
                         ans[j]=!ans[j];
                     }
                }
            deb(a[j]);
            deb(b[j]);
            deb(c[j]);
            deb(d[j]);
                  for(lli k=0; k<6  ; ++k){
                cout<<ans[k];
            }
            cout<<endl;
            }
          cout<<"-------------------------------------------"<<endl;

        }
        lli pow=1;
        lli si=0;
        for(lli i=0; i<64; ++i){
            if(ans[i]){
                si+=pow;
            }
            pow*=2;
        }
        cout<<si<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
  //      cin>>t;
        while(t--){
            solve();
        }
    }