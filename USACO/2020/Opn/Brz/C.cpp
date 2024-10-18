    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    using ld=long double;

    void solve(){
        lli n,t;
        cin>>n>>t;
        
        string s;
        cin>>s;
        
        vector<pair<lli, pair<lli,lli>>> v;
        for(lli i=0; i<t; ++i){
            lli T,x,y;
            cin>>T>>x>>y;
            x--; 
            y--;
            v.pb({T,{x,y}});
        }
        sort(v.begin(), v.end());
        lli x=0;
        lli y=1e9;
        lli z=0;
        for(lli i=0; i<n; ++i){
            bool pos=false;
            for(lli k=0; k<=t; ++k){
                vector<lli> rest (n, 0);
                vector<bool> prend (n,0);
                rest[i]=k;
                prend[i]=1;
                for(auto si: v){
                    lli a=si.second.first;
                    lli b=si.second.second;
                    if(prend[a]){
                        if(prend[b]){
                            rest[a]=max(0ll, rest[a]-1);
                             rest[b]=max(0ll, rest[b]-1);
                        }
                        else{
                            if(rest[a]>0){
                                rest[b]=k;
                                prend[b]=1;
                                rest[a]--;
                            }
                            else{
                                rest[a]=max(0ll, rest[a]-1);
                            }
                        }
                    }
                    else{
                        if(prend[b]){
                            if(rest[b]>0){
                                rest[a]=k;
                                prend[a]=1;
                                rest[b]--;
                            }
                            else{
                                rest[b]=max(0ll, rest[b]-1);
                            }
                        }
                    }
                }
                bool jala=true;
         //       deb(i);
       //         deb(k);
                for(lli i=0; i<n; ++i){
     //               cout<<prend[i];
                    if(prend[i]!=(s[i]=='1')){
                        jala=false;
                    }
                }
   //             cout<<endl;
                if(jala){
                    pos=true;
                    y=min(y, k);
                    z=max(z,k);
                }
            }
            if(pos){
                x++;
            }
        }
        cout<<x<<" "<<y<<" ";
        if(z==t){
            cout<<"Infinity"<<endl;
        }
        else{
            cout<<z<<endl;
        }

    }




    int main(){
        freopen("tracing.in", "r", stdin);
        freopen("tracing.out", "w", stdout);
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
 //       cin>>t;
        while(t--){
            solve();
        }
    }