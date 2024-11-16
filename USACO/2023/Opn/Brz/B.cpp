    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    using ld=long double;

    void solve(){
       lli n,c,p;
       cin>>n>>c>>p;
       vector<string> v1; //noun
       vector<string> v2; //intransitive
       vector<string> v3; //transitive
       vector<string> v4;  //conjunction
       for(lli i=0; i<n; ++i){
        string word, type;
        cin>>word>>type;
        if(type=="noun"){
            v1.pb(word);
        }
        if(type=="transitive-verb"){
            v2.pb(word);
        }
        if(type=="intransitive-verb"){
            v3.pb(word);
        }
        if(type=="conjunction"){
            v4.pb(word);
        }
       }
       lli numofsen=p+v4.size();
       lli ans=0;
       lli sen=0;
       lli intr=0;
       for(lli i=0; i<numofsen; ++i){
        if(i>v1.size() || i>v3.size()) break;
        lli conpos=v1.size()-i;
        lli x=min(conpos/2, min((lli) v2.size(), numofsen-i));
        if(2*x>conpos){
            
        }
       }
    }




    int main(){
        //freopen("billboard.in", "r", stdin);
        //freopen("billboard.out", "w", stdout);
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
     //   cin>>t;
        while(t--){
            solve();
        }
    }