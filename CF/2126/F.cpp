    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    // #define endl '\n'


    void solve(){
        lli n,m;
        cin>>n>>m;
        vector<pair<lli,lli>> arr;
        for(lli i=0; i<m; ++i){
            lli x,y;
            cin>>x>>y;
            x--;
            y--;
            if(x==0 && y==n-1) continue;
            arr.pb({x,y});
        }
        m=arr.size();
        lli ml=-1;
        lli mr=n;
        for(lli i=0; i<m; ++i){
            if(arr[i].first==0) ml=max(ml, arr[i].second);
            if(arr[i].second==n-1) mr=min(mr, arr[i].first);
        }
        vector<bool> used (n,0);
        vector<lli> ans (n, -1);
        lli cant=1e9;

        for(lli i=0; i<n; ++i){

            // Checar si todos salen MEX=0
            bool todos=true;
            bool ninguno=true;
            for(lli j=0; j<m; ++j){
                if(arr[j].first>i || arr[j].second<i) todos=false;
                else ninguno=false;
            }

            if(todos){
                vector<bool> au(n,0);
                vector<lli> aa(n,-1);
                aa[i]=0;
                au[0]=1;
                
                cant=0;
                used=au;
                ans=aa;
                break;
            }


           
            bool izq=false;
            bool der=false;
            
            for(lli j=0; j<m; ++j){
                if(arr[j].first==i) izq=true;
                if(arr[j].second==i) der=true;
            }

             //Checar MEX=1
            if(ninguno){
                 if(cant>1){
                vector<bool> au(n,0);
                vector<lli> aa(n,-1);
                aa[i]=0;
                au[0]=1;
                cant=1;
                used=au;
                ans=aa;
                continue;
                 }
            }

            if(!ninguno && !(izq &&der)){
                if(!izq && i>0){
                    if(cant>1){
                        vector<bool> au(n,0);
                        vector<lli> aa(n,-1);
                        aa[i]=0;
                        aa[i-1]=1;
                        au[0]=1;
                        au[1]=1;
                        cant=1;
                        used=au;
                        ans=aa;
                        continue;
                    }
                }
                 if(!der && i<n){
                    if(cant>1){
                        vector<bool> au(n,0);
                        vector<lli> aa(n,-1);
                        aa[i]=0;
                        aa[i+1]=1;
                        au[0]=1;
                        au[1]=1;
                        cant=1;
                        used=au;
                        ans=aa;
                        continue;
                    }
                }
            }

           

            //MEX=2

            if(i>ml){
                 if(cant>2){
                        vector<bool> au(n,0);
                        vector<lli> aa(n,-1);
                        aa[i]=0;
                        aa[0]=1;
                        au[0]=1;
                        au[1]=1;
                        cant=2;
                        used=au;
                        ans=aa;
                        continue;
                    }
            }  
            else if(i<mr){
                 if(cant>2){
                        vector<bool> au(n,0);
                        vector<lli> aa(n,-1);
                        aa[i]=0;
                        aa[n-1]=1;
                        au[0]=1;
                        au[1]=1;
                        cant=2;
                        used=au;
                        ans=aa;
                        continue;
                    }
            }
            else{
                 if(cant>2){
                        vector<bool> au(n,0);
                        vector<lli> aa(n,-1);
                        aa[i]=0;
                       
                        au[0]=1;
                        au[1]=1;
                        au[2]=1;
                        if(n==3){
                            if(i==1){
                                aa[0]=1;
                                aa[1]=0;
                                aa[2]=2;
                            }
                            else{
                                if(i==0){
                                    aa[0]=0;
                                    aa[1]=2;
                                    aa[2]=1;
                                }
                                else{
                                    aa[0]=1;
                                    aa[1]=2;
                                    aa[2]=0;
                                }
                            }
                        }
                        else{
                            if(i>=2){
                               aa[0]=1;
                               aa[1]=2; 
                            }
                            else{
                                aa[n-1]=1;
                                aa[n-2]=2;
                            }
                        }
                        cant=2;
                        used=au;
                        ans=aa;
                        continue;
                    }
            }
        }

        lli ind=0;
        for(lli i=0; i<n; ++i){
            if(ans[i]==-1){
                while(used[ind]) ind++;
                ans[i]=ind;
                used[ind]=1;
                ind++;
            }
        }

        for(lli i=0; i<n; ++i){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
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