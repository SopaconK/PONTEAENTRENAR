    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
     lli n;
     cin>>n;
     vector<lli> p (n+1,0);
     vector<lli> v (n);
     for(lli i=0; i<n; ++i){
        lli x;
        cin>>x;
        p[x]=i;
     }   
     vector<bool> used (n+1,0);
     for(lli i=0; i<n; ++i) cin>>v[i];
     lli lng=-1;
     for(lli i=0; i<n; ++i){
        if(i==0){
            used[v[i]]=1;
            lng=p[v[i]];
        }   
        else{
            if(v[i]==v[i-1]) continue;
            if(used[v[i]]){
                cout<<"NO"<<endl;
                return;
            }
            used[v[i]]=1;
            if(lng>p[v[i]]){
                cout<<"NO"<<endl;
                return;
            }
            lng=p[v[i]];
            
        }
     }
     cout<<"YES"<<endl;

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