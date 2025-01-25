    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<vector<lli>> v (n, vector<lli> (n));
        vector<lli> w1 (n,0);
        vector<lli> w2 (n,0);
        vector<lli> a1 (n,0);
        vector<lli> a2 (n,0);
        vector<lli> b1 (n,0);
        vector<lli> b2 (n,0);
        lli sum=0;
        for(lli i=0; i<n; ++i){
            for(lli j=0; j<n; ++j){
                cin>>v[i][j];
                if(v[i][j]==0){
                    w1[i]++;
                    w2[j]++;
                }
                if(v[i][j]==1){
                    a1[i]++;
                    a2[j]++;
                    sum++;
                }
                if(v[i][j]==2){
                    b1[i]++;
                    b2[j]++;
                    sum++;
                }
            }
        }

        stack<pair<lli, pair<lli,lli>>> sk;
        

        while(sum>0){
            bool camb=false;
            for(lli i=0; i<n; ++i){
              //  deb(a1[i]);
                //deb(b1[i]);
                //deb(w1[i]);
                if(w1[i]==0 && a1[i]==0 && b1[i]!=0){
                    sum-=b1[i];
                    b1[i]=0;
                    sk.push({1, {i+1, 2}});
                    for(lli j=0; j<n; ++j){
                        b2[j]=max(0ll, b2[j]-1);
                    }
                    camb=true;
                    break;
                }
                 if(w1[i]==0 && b1[i]==0 && a1[i]!=0){
                    sum-=a1[i];
                    a1[i]=0;
                    sk.push({1, {i+1, 1}});
                    for(lli j=0; j<n; ++j){
                        a2[j]=max(0ll, a2[j]-1);
                    }
                    camb=true;
                    break;
                }

                 if(w2[i]==0 && a2[i]==0 && b2[i]!=0){
                    sum-=b2[i];
                    b2[i]=0;
                    sk.push({2, {i+1, 2}});
                    for(lli j=0; j<n; ++j){
                        b1[j]=max(0ll, b1[j]-1);
                    }
                    camb=true;
                    break;
                }
                 if(w2[i]==0 && b2[i]==0 && a2[i]!=0){
                    sum-=a2[i];
                    a2[i]=0;
                    sk.push({2, {i+1, 1}});
                    for(lli j=0; j<n; ++j){
                        a1[j]=max(0ll, a1[j]-1);
                    }
                    camb=true;
                    break;
                }
   
                

            }

           if(!camb){
            cout<<-1<<endl;
                return;
           }

        }

        cout<<sk.size()<<endl;
        while(!sk.empty()){
            cout<<sk.top().first<<" "<<sk.top().second.first<<" "<<sk.top().second.second<<endl;
            sk.pop();
        }

    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        solve();
        
    }