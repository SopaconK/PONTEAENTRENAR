    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
 //   #define endl '\n'

 lli ask=0;
    void query(lli k, vector<lli> & v){
        ask++;
        cout<<"? "<<k<<endl;
        lli q;
        cin>>q;
        v.resize(q);
        for(lli i=0; i<q; ++i){
            cin>>v[i];
            v[i]--;
        }
    }

    void addedge(lli a, lli b, vector<vector<lli>> &edge){
        edge[a][b]=1;
    }
    void solve(){
        ask=0;
        lli n;
        cin>>n;
        vector<lli> sz (n, 1);
        vector<lli> ini (n, 0);
        vector<vector<lli>> edge (n, vector<lli> (n, 0));
        lli act=1;
        ini[0]=1;
        act=2;
        vector<lli> v ={0};
        while(v.size()>0){
            vector<lli> v2;
            query(act, v2);
            if(v2.size()==0) break;
      //      deb(v2.size());
        //    deb(v.size());
            if(v2.size()>v.size()){
                ini[v2[v2.size()-1]]=act;
                  if(v2.size()>=2)addedge(v2[v2.size()-2], v2[v2.size()-1], edge);
            }
            else{
                for(lli i=(v2.size()-1); i<v.size(); ++i){
          //          deb(i);
            //        deb(v2.size()-1);
                    sz[v[i]]=act-ini[v[i]];
                }
                ini[v2[v2.size()-1]]=act;
                if(v2.size()>=2)addedge(v2[v2.size()-2], v2[v2.size()-1], edge);
                
            }
  //          deb("hi");
            act+=sz[v2[v2.size()-1]];
            swap(v, v2);
        }
        lli cant=0;
        for(lli i=0; i<n; ++i){
            for(lli j=0; j<n; ++j){
                if(edge[i][j]) cant++;
            }
        }
        cout<<"! "<<cant<<endl;
        for(lli i=0; i<n; ++i){
            for(lli j=0; j<n; ++j){
                if(edge[i][j]){
                    cout<<i+1<<" "<<j+1<<endl;
                }
            }
        }

      //  deb(ask);


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