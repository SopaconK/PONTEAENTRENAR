    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve1(){
        lli n,c;
        cin>>n>>c;
        vector<string> v (n);
        for(lli i=0; i<n; ++i) cin>>v[i];
        bool eq=1;
        for(lli i=1; i<n; ++i){
            if(v[0][i]!=v[0][i-1]){
                eq=0;
                break;
            }
        }
        if(eq){
            if(c==1){
                if(v[0][0]=='1'){
                    cout<<1<<" "<<1<<endl;
                    return;
                }
                else{
                    for(lli i=1; i<n; ++i){
                        for(lli j=0; j<n; ++j){
                            if(v[i][j]=='1'){
                                cout<<i+1<<" "<<1<<endl;
                                return;
                            }
                        }
                    }
                }
            }
            else{
                if(v[0][0]=='0'){
                    cout<<1<<" "<<1<<endl;
                    return;
                }
                else{
                    for(lli i=1; i<n; ++i){
                        for(lli j=0; j<n; ++j){
                            if(v[i][j]=='0'){
                                cout<<i+1<<" "<<1<<endl;
                                return;
                            }
                        }
                    }
                }
            }
        }
        else{
            if(c==1){
               
                    for(lli i=0; i<n; ++i){
                        if(v[0][i]=='0'){
                            cout<<1<<" "<<i+1<<endl;
                            return;
                        }
                    }
              
            }
            else{
                 
                    for(lli i=0; i<n; ++i){
                        if(v[0][i]=='1'){
                            cout<<1<<" "<<i+1<<endl;
                            return;
                        }
                    }
              
            }
        }
    }


    void solve2(){
        lli n;
        cin>>n;
        string r,c;
        cin>>r>>c;
        bool eq=1;
        for(lli i=1; i<n; ++i){
            if(r[i]!=r[i-1]){
                eq=0;
                break;
            }
        }
        bool con=1;
        for(lli i=0; i<n; ++i){
            if(r[i]!=c[0]){
                con=0;
                break;
            }
        }
        if(eq){
            if(con){
                if(c[0]=='0') cout<<0<<endl;
                else cout<<1<<endl;
            }
            else{
                if(c[0]=='1') cout<<0<<endl;
                else cout<<1<<endl;
            }
        }
        else{
            if(c[0]=='1') cout<<0<<endl;
            else cout<<1<<endl;
        }
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        string s;
        cin>>s;
        int t=1;
        cin>>t;
        while(t--){
            if(s=="first"){
            solve1();
            }
            else{
                solve2();
            }
        }
    }