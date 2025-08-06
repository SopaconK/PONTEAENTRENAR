    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'
    using ld=long double;

    void solve(){
        lli n;
        cin>>n;
        map<string, lli> mp;
        vector<string> ayuda={"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
        sort(ayuda.begin(), ayuda.end());
        for(lli i=0; i<8; ++i){
            mp[ayuda[i]]=i;
        }
        vector<pair<lli,lli>> conditions (n);
        for(lli i=0; i<n; ++i){
            string s;
            cin>>s;
            string aux;
            cin>>aux;cin>>aux;cin>>aux;cin>>aux;
            string s2;
            cin>>s2;
            conditions[i]={mp[s],mp[s2]};
        }

        vector<lli> v ={0,1,2,3,4,5,6,7};
        do{
            vector<lli> pos (8);
            for(lli i=0; i<8; ++i){
                pos[v[i]]=i;
            }
            bool cumple=1;
            for(lli i=0; i<n; ++i){
                lli x=pos[conditions[i].first];
                lli y=pos[conditions[i].second];
                lli d=abs(x-y);
                if(d>1) cumple=0;
            }
            if(cumple){
                for(lli i=0; i<8; ++i){
                    cout<<ayuda[v[i]]<<endl;
                }
                return;
            }
        }while(next_permutation(v.begin(), v.end()));

    }




    int main(){
        freopen("lineup.in", "r", stdin);
        freopen("lineup.out", "w", stdout);
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
 //       cin>>t;
        while(t--){
            solve();
        }
    }