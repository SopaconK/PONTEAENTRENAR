    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        lli pot=1;
        for(lli i=1; i<=n-1; ++i) pot*=2;

        lli q;
        cin>>q;
        while(q--){
            char c1,c2;
            cin>>c1>>c2;
            if(c1=='-'){
                lli x,y;
                cin>>x>>y;
                x--;
                y--;
                lli ans=0;
                lli p=pot;
                while(p>=1){
                    bool a=(x>=p);
                    bool b=(y>=p);
                    if(a&& b){
                        ans+=1;
                    }
                    else if(a){
                        ans+=2;
                    }
                    else if(b){
                        ans+=3;
                    }
                    
                    
                    ans*=4;
                    x%=p;
                    y%=p;
                    p/=2;
                }
                ans/=4;
                ans++;
                cout<<ans<<endl;
            }
            else{
                lli d;
                cin>>d;
                d--;
                vector<lli> v (n);
                for(lli i=n-1; i>=0; --i){
                    v[i]=d%4;
                    d/=4;
                }
                lli x=0;
                lli y=0;
                lli p=pot;
                for(lli i=0; i<n; ++i){
                    
                    if(v[i]==0){
                        //na
                    }
                    else if(v[i]==1){
                        x+=p;
                        y+=p;
                    }
                    else if(v[i]==2){
                        x+=p;
                    }
                    else{
                        y+=p;
                    }
                   p/=2;
                }
                x++;
                y++;
                
                cout<<x<<" "<<y<<endl;
            }
        }
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