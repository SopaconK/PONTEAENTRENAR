    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        lli cant1=0;
        lli cant2=0;
        map<lli,lli> mp;
        map<lli,lli> mp2;
        for(lli i=0; i<n; ++i){
            lli x;
            cin>>x;
            if(mp[x]==0){
                cant1++;
            }
            mp[x]++;
        }
        for(lli i=0; i<n; ++i){
            lli x;
            cin>>x;
            if(mp2[x]==0){
                cant2++;
            }
            mp2[x]++;
        }
        if(cant1>cant2) swap(cant1,cant2);
        if(cant1>=2){
            cout<<"YES"<<endl;
            return;
        }
        if(cant2>=3){
            cout<<"YES"<<endl;
            return;
        }
        cout<<"NO"<<endl;
        return;

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