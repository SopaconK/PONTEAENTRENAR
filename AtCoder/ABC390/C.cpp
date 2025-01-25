    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli h,w;
        cin>>h>>w;
        vector<string> v (h);
        for(lli i=0;i<h; ++i){
            cin>>v[i];
        }  
        bool exists=false;
        lli a,b,c,d;
        for(lli i=0; i<h; ++i){
            for(lli j=0; j<w; ++j){
                if(v[i][j]=='#'){
                    exists=true;
                    a=i;
                    b=i;
                    c=j;
                    d=j;
                    break;
                }
            }
        }
        if(!exists){
            cout<<"Yes"<<endl;
            return;
        }
        for(lli i=0; i<h; ++i){
            for(lli j=0; j<w; ++j){
                if(v[i][j]=='#'){
                    a=min(a,i);
                    b=max(b,i);
                    c=min(c,j);
                    d=max(d,j);
                }
            }
        }

        for(lli i=a; i<=b; ++i){
            for(lli j=c; j<=d; ++j){
                if(v[i][j]=='.'){
                    cout<<"No"<<endl;
                    return;
                }
            }
        }
        cout<<"Yes"<<endl;

        

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