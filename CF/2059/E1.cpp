    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m;
        cin>>n>>m;
        vector<lli> a (n*m);
        for(lli i=0; i<n*m; ++i){
            cin>>a[i];
        }
        vector<lli> pos (2*n*m+5,-1);
        vector<lli> b (n*m);
        for(lli i=0; i<n*m; ++i){
            cin>>b[i];
            pos[b[i]]=i;
        }

        lli aux=1;
        if(pos[a[0]]==-1){
            cout<<n*m<<endl;
            return;
        }
        for(lli i=1; i<n*m; ++i){
   //         deb(pos[a[i]]);
            if(pos[a[i]]>=pos[a[i-1]]+1){
                aux++;
            }
            else{
                break;
            }
        }
     //   deb(aux);
        lli p=pos[a[0]];
        if(p>=m){
            cout<<n*m-aux<<endl;
            return;
        }
        lli ind=0;
        lli aux2=0;
        for(lli i=0; i<aux; ++i){
            if(pos[a[i]]>=m*(i/m +1)-1){
                //si jala 
            }
            else{
                  p=pos[a[i]];
                lli x=p%m;
                bool works=true;
                for(lli y=i+1; y<i+(m-x); ++y){
                    if(pos[a[y]]!=pos[a[y-1]]+1){
                        works=false;
                        break;
                    }
                }
                if(works){
                    i=i+m-x-1;
                }
                else break;
                }
                aux2=i+1;
        }
    
        cout<<n*m-aux2<<endl;


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