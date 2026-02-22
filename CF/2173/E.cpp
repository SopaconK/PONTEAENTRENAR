    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    //#define endl '\n'


    bool query(lli x, lli y){
        x++;
        y++;
        cout<<"? "<<x<<" "<<y<<endl;
        lli a,b;
        cin>>a>>b;
        if(x==a && y==b) return true;
        return false;
    }

    void solve(){
        lli n;
        cin>>n;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i) cin>>v[i];
    
        vector<lli> pos (n);
        for(lli i=0; i<n; ++i){
            v[i]--;
            pos[v[i]]=i;
        }
        if(n%2){
            lli k=n/2;
            while(pos[k]!=k){
                if(query(k, pos[k])){
                    lli a=k;
                    lli b=pos[k];
                    swap(pos[v[a]], pos[v[b]]);
                    swap(v[a], v[b]);
                }
                else{
                    lli a=k;
                    lli b=pos[k];
                    a=n-1-a;
                    b=n-1-b;
                    swap(pos[v[a]], pos[v[b]]);
                    swap(v[a], v[b]);
                }
            }
        }
        for(lli i=0; i<n; ++i ){
            if(pos[i]+pos[n-1-i] != n-1){

                if(query(n-1-pos[n-1-i], pos[i])){
                    lli a=n-1-pos[n-1-i];
                    lli b=pos[i];
                    swap(pos[v[a]], pos[v[b]]);
                    swap(v[a], v[b]);
                }
                else{
                    lli a=n-1-pos[n-1-i];
                    lli b=pos[i];
                    a=n-1-a;
                    b=n-1-b;
                    swap(pos[v[a]], pos[v[b]]);
                    swap(v[a], v[b]);
                }
            }
        }

        for(lli i=0; i<n; ++i){
            while(pos[i]!=i || pos[n-1-i]!=n-1-i){
                lli k;
                if(pos[i]!=i) k=i;
                else k=n-1-i;
                if(query(k, pos[k])){
                    lli a=k;
                    lli b=pos[k];
                    swap(pos[v[a]], pos[v[b]]);
                    swap(v[a], v[b]);
                }
                else{
                    lli a=k;
                    lli b=pos[k];
                    a=n-1-a;
                    b=n-1-b;
                    swap(pos[v[a]], pos[v[b]]);
                    swap(v[a], v[b]);
                }

            }
        }
        cout<<"!"<<endl;


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