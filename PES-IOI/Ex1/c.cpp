    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back

    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

   

    auto comp=[](pair<int,int> a, pair<int,int> b){
        if(a.first!=b.first){
            return a.first > b.first;
        }
        return a.second < b.second;
    };


    void solve(){
        int n;
        cin >>n;
        vector<pair<int,int>> v (n);
        for(int i=0; i<n; ++i){
            int c,q;
            cin>>c>>q;
            v.pb({q,c});
        }
        int k;
        cin>>k;
        vector<pair<int,int>> queries (k);
        for(int i=0; i<k; ++i){
            int ayuda;
            cin>>ayuda;
            queries[i]={ayuda, i};
        } 
        sort(v.begin(), v.end(), comp);
        sort(queries.begin(), queries.end());
        vector<int> ans (k,0);


    //   vector<int> aux (k,0);
    //   segtree *tree= new segtree(0,k-1);
        vector<pair<int,int>> rangos;
        vector<int> val1 (k,0);   
        vector<int> val2 (k,0);
        rangos.pb({0,k-1});
        const int lim=1500;
        for(int asdas=0; asdas<n; ++asdas){

            if(rangos.size()>=lim){

                for(int i=0; i<rangos.size(); ++i){
                    for(int j=rangos[i].first; j<=rangos[i].second; ++j){
                        ans[queries[j].second]+=val1[rangos[i].first];
                        queries[j].first-=val2[rangos[i].first];
                    }
                }
    //         tree=new segtree(0,k-1);
                rangos={{0,k-1}};
                for(int i=0; i<k; ++i){
                    val1[i]=0;
                    val2[i]=0;
                }
                
                sort(queries.begin(), queries.end());
            }
            
            int ini=v[asdas].second;
            vector<pair<int,int>> rangos2;

    //        deb(ini);
            for(int i=0; i<rangos.size(); ++i){
        //      deb(i);
                int l=rangos[i].first;
                int r=rangos[i].second;
                int cost=ini+val2[l];
        //        deb(l);
    //          deb(r);
    //            deb(cost);
                while(l<r-1){
                    int m=(l+r)/2;
                    if(queries[m].first<cost){
                        l=m;
                    }
                    else{
                        r=m-1;
                    }
                }
        //      deb(l);
        //        deb(r);
    //          deb(queries[l].first);
    //            deb(queries[r].first);
                if(queries[r].first<cost){
                    l=r;
                }
                if(queries[l].first<cost){
                    rangos2.pb({rangos[i].first, l});
                    if(l+1<=rangos[i].second){
                        val1[l+1]=val1[rangos[i].first]+1;
                        val2[l+1]=val2[rangos[i].first]+ini;

                        rangos2.pb({l+1,rangos[i].second});
                    }
            //     deb("xd");
                }
                else{
                
    //                rangos2.pb({rangos[i].first, l});
                    if(l<=rangos[i].second){
                        val1[l]=val1[rangos[i].first]+1;
                        val2[l]=val2[rangos[i].first]+ini;
                        rangos2.pb({l,rangos[i].second});
                    }
                }
            }

            rangos=rangos2;


        }
        for(int i=0; i<rangos.size(); ++i){
                    for(int j=rangos[i].first; j<=rangos[i].second; ++j){
                        ans[queries[j].second]+=val1[rangos[i].first];
                        queries[j].first-=val2[rangos[i].first];
                    }
                }
        for(int i=0; i<k; ++i){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        

    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
        //cin>>t;
        while(t--){
            solve();
        }
    }