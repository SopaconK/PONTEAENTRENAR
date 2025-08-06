    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        map<string, vector<lli>> mp1;
        map<string, vector<lli>> mp2;
        for(lli i=0; i<n; ++i){
            string s1,s2;
            cin>>s1>>s2;
            mp1[s1].pb(i);
            mp2[s2].pb(i);
        }
        vector<vector<bool>> ady (n, vector<bool> (n, 0));
        for(auto a:mp1){
            lli sz=a.second.size();
            for(lli i=0; i<sz; ++i){
                for(lli j=i+1; j<sz; ++j){
                    ady[a.second[i]][a.second[j]]=1;
                    ady[a.second[j]][a.second[i]]=1;
                }
            }
        }
        for(auto a:mp2){
            lli sz=a.second.size();
            for(lli i=0; i<sz; ++i){
                for(lli j=i+1; j<sz; ++j){
                    ady[a.second[i]][a.second[j]]=1;
                    ady[a.second[j]][a.second[i]]=1;
                }
            }
        }

        lli ans=0;
        lli tam=1<<n;
  //      deb(tam);
        vector<vector<bool>> st (tam, vector<bool> (n,0));
        for(lli i=0; i<n; ++i){
            st[0][i]=1;
        }
        for(lli i=1; i<tam; ++i){
            lli prend=0;
            for(lli j=0; j<n; ++j){
                if((i>>j )% 2){
        //            if(i==2) deb(j);
                    prend++;
                }
            }
    //        deb(i);
      //      deb(prend);
            for(lli j=0; j<n; ++j){
                if(i>>j % 2){
                    lli aux=i^(1<<j);
                    if(aux==0){
                        st[i][j]=1;
                    }
                    for(lli k=0; k<n; ++k){
                        if((aux>>k) % 2){
                            if(st[aux][k] && ady[j][k]){
                                st[i][j]=1;
                                break;
                            }
                            
                        }
                    }   
                }
                
                if(st[i][j]){
   //                 if(prend>ans){
     //                   deb(i);
       //                 deb(j);
         //               deb(prend);
           //         }
                    ans=max(ans, prend);
                }
  //              cout<<st[i][j]<<" ";
            }
//            cout<<endl;
        }
  //      deb(ans);
        cout<<n-ans<<endl;
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