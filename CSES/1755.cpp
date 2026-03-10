    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        string s;
        cin>>s;
        map<char, lli> mp;
        for(char c: s){
            mp[c]++;
        }
        lli imp=0;
        lli auxi=-1;
        for(char c='A'; c<='Z'; ++c){
            if(mp[c]%2){
                imp++;
                auxi=c;
            }
        }
        if(imp>1){
            cout<<"NO SOLUTION"<<endl;
            return;
        }
        string aux="";
        for(char c='A'; c<='Z'; ++c){
         
            while(mp[c]>1){
                aux+=c;
                mp[c]-=2;
            }
        }
        string ans;
        if(imp>0){
            ans=aux;
            ans+=auxi;
            reverse(aux.begin(), aux.end());
            ans+=aux;
        }
        else{
            ans=aux;
            reverse(aux.begin(), aux.end());
            ans+=aux;
        }

        cout<<ans<<endl;


    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
       // cin>>t;
        while(t--){
            solve();
        }
    }