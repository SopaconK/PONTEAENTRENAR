    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,m,k;
        cin>>n>>m>>k;
        lli maxim=0;
        lli act=0;
        lli notfind=k;
        vector<lli> pos (k+1,-1);
        for(lli i=0; i<k; ++i){
            lli x;
            cin>>x;
            pos[x]=i;
            act++;
             maxim=max(maxim, act);
            while(notfind>0 && pos[notfind]!=-1){
                notfind--;
                act--;
            }
            
            
        }
        lli aux=n*m;
        if(aux>=maxim+3){
            cout<<"YA"<<endl;
        }
        else cout<<"TIDAK"<<endl;
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